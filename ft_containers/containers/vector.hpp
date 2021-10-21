/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:19:35 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/20 21:33:53 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

#include "../iterators/random_access_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../iterators/type_traits.hpp"
#include "../utils/distance.hpp"
#include "../utils/lexicographical_compare.hpp"
#include "../utils/equal.hpp"
#include <memory>
#include <limits>
#include <exception>
#include <iostream>
#include <algorithm>

namespace ft
{
	template < typename T, typename Alloc = std::allocator<T> >
	class vector
	{

   	public:

		typedef vector<T, Alloc>								self_type;
		typedef T												value_type;
		typedef typename Alloc::pointer							pointer;
      	typedef typename Alloc::const_pointer					const_pointer;
      	typedef typename Alloc::reference						reference;
      	typedef typename Alloc::const_reference					const_reference;
      	typedef ft::random_access_iterator<pointer, vector> 	iterator;
      	typedef ft::random_access_iterator<const_pointer, vector>
		  	const_iterator;
      	typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
      	typedef ft::reverse_iterator<iterator>					reverse_iterator;
      	typedef size_t											size_type;
      	typedef std::ptrdiff_t									difference_type;
      	typedef Alloc											allocator_type;

		// Constructors / Destructor / Assignment operator 

		explicit vector( const allocator_type & alloc = allocator_type() )
			: _alloc(alloc), _start(NULL), _end(NULL), _end_of_storage(NULL)
		{
			return ;
		}

		explicit vector( size_type n, const value_type & val = value_type(),
            const allocator_type & alloc = allocator_type() )
			: _alloc(alloc), _start(_alloc.allocate(n)), _end(_start + n),
				_end_of_storage(_end)
		{
			assign(n, val);
		}

		template <class InputIterator>
        vector( InputIterator first, InputIterator last,
            const allocator_type & alloc = allocator_type(),
			typename ft::enable_if<!ft::isIntegral<InputIterator>::value,
			InputIterator>::type* = NULL )
			: _alloc(alloc), _start(NULL), _end(NULL), _end_of_storage(NULL)
		{
			assign(first, last);
		}
		
		vector( const self_type & src ) : _alloc(src.get_allocator()),
			_start(NULL), _end(NULL), _end_of_storage(NULL)
		{
			if (src._start == NULL)
				return ;
			*this = src;
		}

		~vector( void )
		{
			clear();
			if (capacity() != 0)
				_alloc.deallocate(_start, capacity());
		}

		self_type &	operator=( const self_type& rhs )
		{
			if (this != &rhs)
			{
				size_type oldCapacity = capacity();
				_alloc = rhs.get_allocator();
				_start = _alloc.allocate(rhs.capacity());
				_end = _start + rhs.size();
				if (oldCapacity < rhs.size())
					_end_of_storage = _start + rhs.size();
				else
					_end_of_storage = _start + oldCapacity;
				assign(rhs.begin(), rhs.end());
			}
			return *this;
		}

		// Iterators

		iterator begin( void )
		{
			return iterator(_start);
		}

		const_iterator begin( void ) const
		{
			return const_iterator(_start);
		}

		iterator end( void )
		{
			return iterator(_end);
		}

		const_iterator end( void ) const
		{
			return const_iterator(_end);
		}

		reverse_iterator	rbegin( void )
		{
			return reverse_iterator(end());
		}

		const_reverse_iterator	rbegin( void ) const
		{
			return reverse_iterator(end());
		}

		reverse_iterator	rend( void )
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator	rend( void ) const
		{
			return reverse_iterator(begin());
		}

		// Capacity

		size_type	size( void ) const
		{
			return _end - _start;
		}

		size_type	max_size( void ) const
    	{
			const size_type diffMax = size_type(-1) / sizeof(value_type);
			const size_type allocMax = alloc_traits::max_size(_alloc);
			
			return std::min(diffMax, allocMax);
		}

		void	resize( size_type n, value_type val = value_type() )
		{
			if (n > size())
			{
				if (n > capacity())
				{
					size_type newCapacity = size() * 2;

					if (newCapacity == 0 || newCapacity < n)
						newCapacity = n;
					reserve(newCapacity);
				}	
				for (size_type i = size(); i < n; i++)
					_alloc.construct(_start + i, val);
				_end = _start + n;
			}
			else if (n < size())
			{
				_Destroy(_start + n, _end, _alloc);
				_end = _start + n;
			}
		}

		size_type	capacity( void ) const
		{
			return _end_of_storage - _start;
		}

		bool	empty( void ) const
		{
			return _start == _end;
		}

		void	reserve( size_type n )
		{
			if (n > max_size())
				std::__throw_length_error(__N("ft_vector::reserve"));
			if (capacity() < n)
			{
				pointer	tmp = _alloc.allocate(n);
				const size_type oldSize = size();
				for (size_type i = 0; i < oldSize; i++)
					_alloc.construct(tmp + i, *(_start + i));
				_Destroy(_start, _end, _alloc);
				_alloc.deallocate(_start, capacity());
				_start = tmp;
				_end = tmp + oldSize;
				_end_of_storage = _start + n;
			}
		}

		// Element access
		
		reference	operator[]( size_type n )
		{
			return *(_start + n);
		}

  		const_reference	operator[]( size_type n ) const
		{
			return *(_start + n);
		}

		reference	at( size_type n )
		{
			if (n >= size())
			{
				std::__throw_out_of_range_fmt(__N("ft_vector::at: n "
			       "(which is %zu) >= this->size() "
			       "(which is %zu)"), n, size());
			}
			return (*this)[n];
		}

		const_reference	at( size_type n ) const
		{
			if (n >= size())
			{
				std::__throw_out_of_range_fmt(__N("ft_vector::at: n "
			       "(which is %zu) >= this->size() "
			       "(which is %zu)"), n, size());
			}
			return (*this)[n];
		}

		reference	front( void )
		{
			return *begin();
		}

		const_reference	front( void ) const
		{
			return *begin();
		}

		reference	back( void )
		{
			return *(end() - 1);
		}

		const_reference	back( void ) const
		{
			return *(end() - 1);
		}

		// Modifiers

		template <class InputIterator>
  		void	assign( InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::isIntegral<InputIterator>::value,
			InputIterator>::type* = NULL )
		{
			clear();
			insert(begin(), first, last);
		}

		void assign( size_type n, const value_type & val )
		{
			clear();
			insert(begin(), n, val);
		}

		void push_back( const value_type & val ) 
		{
			if (_end != _end_of_storage)
			{
				_alloc.construct(_end, val);
				_end++;
			}
			else
			{
				size_type newCapacity = capacity() * 2;

				if (newCapacity == 0)
					newCapacity = 1;
				reserve(newCapacity);
				_alloc.construct(_end, val);
				_end++;
			}
		}

		void pop_back( void )
		{
			_end--;
			_Destroy(_end, _end + 1, _alloc);
		}

		iterator insert( iterator position, const value_type & val )
		{
			if (_end != _end_of_storage)
			{
				_alloc.construct(_end++, val);
				for (iterator it = end() - 1; it != position; it--)
					std::swap(*it, *(it - 1));
			}
			else
			{
				difference_type offset = position - begin();
				size_type		newCapacity = capacity() * 2;

				if (newCapacity == 0)
					newCapacity = 2;
				reserve(newCapacity);
				position = begin() + offset;
				_alloc.construct(_end++, val);
				for (iterator it = end() - 1; it != position; it--)
					std::swap(*it, *(it - 1));
			}
			return position;
		}

		void insert( iterator position, size_type n, const value_type & val )
		{
			if (size_type(_end_of_storage - _end) >= n)
			{
				while (n--)
					insert(position++, val);
			}
			else
			{
				const size_type len = size() + std::max(size(), n);
				const difference_type offset = position - begin();

				reserve(len);
				position = begin() + offset;
				while (n--)
					insert(position++, val);
			}
		}

		template <typename InputIterator>
    	void insert(iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::isIntegral<InputIterator>::value,
			InputIterator>::type* = NULL)
		{
			size_type lenght = ft::distance(first, last);
			if (size_type(_end_of_storage - _end) >= lenght)
			{
				while (first != last)
					insert(position++, *first++);
			}
			else
			{
				const size_type len = size() + std::max(size(), lenght);
				const difference_type offset = position - begin();

				reserve(len);
				position = begin() + offset;
				while (first != last)
					insert(position++, *first++);
			}
		}

		iterator erase( iterator position )
		{
			for (iterator it = position; it != end() - 1; it++)
				std::swap(*it, *(it + 1));
			_end--;
			return position;
		}

		iterator erase( iterator first, iterator last )
		{
			while (first != last)
			{
				erase(first);
				last--;
			}	
			return first;
		}

		void swap( vector & x )
		{
			std::swap(_start, x._start);
    		std::swap(_end, x._end);
    		std::swap(_end_of_storage, x._end_of_storage);
		}

		void clear( void )
		{
			erase(begin(), end());
		}

		// Allocator

		allocator_type	get_allocator() const
		{
			return _alloc;
		}

	private:

		typedef __gnu_cxx::__alloc_traits<allocator_type>	alloc_traits;

		allocator_type	_alloc;
		pointer			_start;
		pointer			_end;
		pointer			_end_of_storage;

		void _check_init_lenght( size_type n )
		{
			if (n > max_size())
			 std::__throw_length_error(
	    		__N("cannot create ft::vector larger than max_size()"));
		}

	}; // class vector

	template<typename T, typename Alloc>
    bool	operator==( const vector<T, Alloc> & x,
		const vector<T, Alloc> & y )
    {
		return (x.size() == y.size() &&
			ft::equal(x.begin(), x.end(), y.begin()));
	}

	template<typename T, typename Alloc>
    bool	operator<( const vector<T, Alloc> & x, const vector<T, Alloc> & y )
    {
		return ft::lexicographical_compare(x.begin(), x.end(),
			y.begin(), y.end());
	}

	template<typename T, typename Alloc>
    bool	operator!=( const vector<T, Alloc> & x,
		const vector<T, Alloc> & y )
    {
		return !(x == y);
	}

	template<typename T, typename Alloc>
    bool	operator>( const vector<T, Alloc> & x, const vector<T, Alloc> & y )
    {
		return (y < x);
	}

	template<typename T, typename Alloc>
    bool	operator<=( const vector<T, Alloc> & x,
		const vector<T, Alloc> & y )
    {
		return !(y < x);
	}

	template<typename T, typename Alloc>
    bool	operator>=( const vector<T, Alloc> & x,
		const vector<T, Alloc> & y )
    {
		return !(x < y);
	}

	template<typename T, typename Alloc>
    void	swap( vector<T, Alloc> & x, vector<T, Alloc> & y )
    {
		y.swap(x);
	}

} // namespace ft

#endif
