/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:04:23 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/29 16:39:56 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_iTERATOR_H
# define RANDOM_ACCESS_iTERATOR_H

# include "iteratorTraits.hpp"
# include "typeTraits.hpp"

namespace ft
{

	template<typename T>
	class random_access_iterator
	{


	public:
		
		typedef T								value_type;
		typedef	value_type*						pointer;
		typedef	value_type&						reference;
		typedef const value_type*				const_pointer;
		typedef	const value_type&				const_reference;
		typedef typename std::ptrdiff_t			difference_type;
		typedef ft::random_access_iterator_tag	iterator_category;

		/*
		** Constructs a random_access iterator with the
		** default value of iterator. (pointer)
		*/

		random_access_iterator() : _current(0)
		{
			return ;
		}

		/*
		** Constructs a random_access iterator that points to it.
		*/

		explicit random_access_iterator( pointer ptr ) : _current(ptr)
		{
			return ;
		}

		random_access_iterator( const random_access_iterator& rhs )
			: _current(rhs._current)
		{
			return ;
		}

		random_access_iterator& operator=( const random_access_iterator& rhs )
		{
			if (this != &rhs)
				_current = rhs._current;
			return *this;
		}

		/*
		** Destructor
		*/

		~random_access_iterator( void )
		{
			return ;
		}

		/*
		** Convert a iterator in const_iterator.
		*/

		operator random_access_iterator<value_type const>() const
		{
			return random_access_iterator<value_type const>(_current);
		}

		/*
		** Returns a reference to the element pointed to by the iterator.
		*/

		reference	operator*( void ) const
		{
				return *_current;
		}

		/*
		** Returns a pointer to the element pointed to by the iterator.
		*/

		pointer	operator->( void ) const
		{
				return _current;
		}

		/*
		** Pre increment version
		** Advances the random_access_iterator by one position.
		*/

		random_access_iterator& operator++( void )
		{
			++_current;
			return *this;
		}

		/*
		** Post increment version
		** Advances the random_access_iterator by one position.
		*/

		random_access_iterator	operator++( int ) 
		{
			return random_access_iterator(_current++);
		}

		/*
		** Pre decrement version
		** Decreases the random_access_iterator by one position.
		*/

		random_access_iterator&	operator--( void )
		{
			--_current;
			return *this;
		}

		/*
		** Post decrement version
		** Decreases the random_access_iterator by one position.
		*/

		random_access_iterator	operator--( int )
		{
			return random_access_iterator(_current--);
		}

		/*
		** Accesses the element located n positions away from the element
		** currently pointed to by the iterator.
		** If such an element does not exist, it causes undefined behavior.
		*/

		reference	operator[]( difference_type n ) const
		{
			return _current[n];
		}

		/*
		** Advances the random_access_iterator by n element positions.
		*/

		random_access_iterator & operator+=( difference_type n )
		{
			_current += n;
			return *this;
		}

		/*
		** Returns a random_access_iterator pointing to the element located
		** n positions away from the element the iterator currently points to.
		*/

		random_access_iterator	operator+( difference_type n ) const
		{
			return random_access_iterator(_current + n);
		}

		/*
		** Descreases the reverse_iterator by n element positions.
		*/

		random_access_iterator&	operator-=( difference_type n )
		{
			_current -= n;
			return *this;
		}

		/*
		** Returns a reverse iterator pointing to the element located 
		** n positions before the element the iterator currently points to.
		*/

		random_access_iterator	operator-( difference_type n ) const
		{
			return random_access_iterator(_current - n);
		}

		/*
		** Returns a copy of _current
		*/

		pointer	base( void ) const
		{
			return _current;
		}

	protected:

		pointer _current;
	};

	/*
	** Performs the appropriate comparison operation between the
	** reverse_iterator objects x (x) and y (y).
	*/

	template<typename L, typename R>
    bool	operator==( const random_access_iterator<L>& x,
	       const random_access_iterator<R>& y )
    {
		return x.base() == y.base();
	}

	template<typename L, typename R>
	bool	operator!=( const random_access_iterator<L>& x,
	       const random_access_iterator<R>& y )
    {
		return x.base() != y.base();
	}

	template<typename L, typename R>
	bool	operator<( const random_access_iterator<L>& x,
	       const random_access_iterator<R>& y )
    {
		return x.base() < y.base();
	}

	template<typename L, typename R>
	bool	operator>( const random_access_iterator<L>& x,
	       const random_access_iterator<R>& y )
    {
		return x.base() > y.base();
	}

	template<typename L, typename R>
	bool	operator<=( const random_access_iterator<L>& x,
	       const random_access_iterator<R>& y )
    {
		return x.base() <= y.base();
	}

	template<typename L, typename R>
	bool	operator>=( const random_access_iterator<L>& x,
	       const random_access_iterator<R>& y )
    {
		return x.base() >= y.base();
	}

	/*
	** operator- must accept mixed iterator/const_iterator parameters.
	*/

	template<typename L, typename R>
	typename random_access_iterator<L>::difference_type
    operator-( const random_access_iterator<L>& x,
	    const random_access_iterator<R>& y )
	{
		return x.base() - y.base();
	}

	/*
	** Returns the distance between lhs (x) and rhs (y).
	*/

	template<typename T>
    typename random_access_iterator<T>::difference_type
    operator-( const random_access_iterator<T>& x,
	      const random_access_iterator<T>& y )
    {
		return x.base() - y.base();
	}

	/*
	** Returns a random_access_iterator pointing to the element located n
	** positions away from the element pointed to by x.
	*/

	template<typename T>
    random_access_iterator<T>
    operator+( typename random_access_iterator<T>::difference_type n,
		const random_access_iterator<T>& i )
    {
		return (i + n);
	}

} // namespace ft

#endif
