/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:45:48 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/23 13:13:28 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

# include "../utils/less.hpp"
# include "../utils/pair.hpp"
# include "../utils/rb_tree.hpp"
# include "../iterators/iterator_traits.hpp"
# include <memory>

namespace ft
{

	template<typename Key, typename T, typename Compare = ft::less<Key>,
		typename Alloc = std::allocator<ft::pair<Key const, T> > >
	class map
	{
		
	public:

		typedef Key										key_type;
		typedef T										mapped_type;
		typedef ft::pair<const key_type, mapped_type>	value_type;
		typedef	Compare									key_compare;

		/*
		** Nested function class to compare elements.
		*/

		class value_compare
			: public std::binary_function<value_type, value_type, bool>
		{
			
		protected:
			
			Compare _comp;

		public:
			
			typedef bool		result_type;
			typedef value_type	first_argument_type;
			typedef value_type	second_argument_type;

			value_compare(Compare c): _comp(c)
			{
				return;
			}

			bool operator()( const value_type& x, const value_type& y ) const
			{
				return (_comp(x.first, y.first));
			}

		}; // class value_compare

			typedef Alloc									allocator_type;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;
			typedef value_type*								pointer;
			typedef const value_type*						const_pointer;
		
	private:

		typedef typename ft::RBTree<Key, T, key_compare, allocator_type>
			tree_type;

	public:

		typedef typename tree_type::iterator			iterator;
		typedef typename tree_type::const_iterator		const_iterator;
		typedef typename tree_type::reverse_iterator	reverse_iterator;
		typedef typename tree_type::const_reverse_iterator
			const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type
			difference_type;
		typedef size_t									size_type;


	public:

		/*
		** Empty container constructor (default constructor)
		** Constructs an empty container, with no elements.
		*/

		explicit map( const Compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type() )
			: _tree(comp, allocator_type(alloc))
		{
			return ;
		}

		/*
		** Range constructor
		** Constructs a container with as many elements
		** as the range [first,last), with each element constructed
		** from its corresponding element in that range.
		*/

		template<typename InputIterator>
		map( InputIterator first, InputIterator last,
			const Compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type() )
			: _tree(comp, allocator_type(alloc))
		{
			_tree.insert(first, last);
		}

		/*
		** Copy constructor
		** Constructs a container with a copy of each of the elements in x.
		*/

		map( const map& src ) : _tree(src._tree)
		{
			return ;
		}

		/*
		** Destructor
		** This destroys all container elements,
		** and deallocates all the storage capacity allocated
		** by the map container using its allocator.
		*/

		virtual ~map( void )
		{
			clear();
		}

		/*
		** Copy container content
		** Assigns new contents to the container,
		** replacing its current content.
		*/

		map	&operator=( const map& rhs )
		{
			_tree = rhs._tree;
			return (*this);
		}

		/*
		** Returns an iterator referring to the first element
		** in the map container.
		*/

		iterator begin( void )
		{
			return (_tree.begin());
		}

		/*
		** Returns a const iterator referring to the first element
		** in the map container.
		*/

		const_iterator begin( void ) const
		{
			return (_tree.begin());
		}

		/*
		** Returns an iterator referring to the past-the-end
		** element in the map container.
		*/

		iterator end( void )
		{
			return (_tree.end());
		}

		/*
		** Returns a const iterator referring to the past-the-end
		** element in the map container.
		*/

		const_iterator end( void ) const
		{
			return (_tree.end());
		}

		/*
		** Returns a reverse iterator pointing to the last element
		** in the container.
		*/

		reverse_iterator rbegin( void )
		{
			return (_tree.rbegin());
		}

		/*
		** Returns a const reverse iterator pointing to the last element
		** in the container.
		*/

		const_reverse_iterator rbegin( void ) const
		{
			return (_tree.rbegin());
		}

		/*
		** Returns a reverse iterator pointing to the theoretical element
		** right before the first element in the map container.
		*/

		reverse_iterator rend( void )
		{
			return (_tree.rend());
		}

		/*
		** Returns a const reverse iterator pointing to the theoretical element
		** right before the first element in the map container.
		*/

		const_reverse_iterator rend( void ) const
		{
			return (_tree.rend());
		}

		/*
		** Returns whether the map container is empty.
		*/

		bool empty( void ) const
		{
			return (_tree.empty());
		}

		/*
		** Returns the number of elements in the map container.
		*/

		size_type size( void ) const
		{
			return (_tree.size());
		}

		/*
		** Returns the maximum number of elements
		** that the map container can hold.
		*/

		size_type max_size( void ) const
		{
			return (_tree.max_size());
		}

		/*
		** If key matches the key of an element in the container,
		** the function returns a reference to its mapped value.
		** If key does not match the key of any element in the container,
		** the function inserts a new element with that key and returns
		** a reference to its mapped value.
		*/

		mapped_type &operator[]( const key_type& key )
		{
			return (_tree[key]);
		}

		/*
		** Extends the container by inserting one single element, 
		** effectively increasing the container size by one.
		*/

		ft::pair<iterator, bool> insert( const value_type& val )
		{
			return (_tree.insert(val));
		}

		/*
		** Extends the container by inserting one single element at a given
		** position, effectively increasing the container size by one.
		** Position is an hint for the position where
		** the element can be inserted.
		*/

		iterator insert( iterator position, const value_type& val )
		{
			return (_tree.insert(position, val));
		}

		/*
		** Extends the container by inserting new elements,
		** effectively increasing the container size by
		** the number of elements inserted.
		*/

		template<typename InputIterator>
		void insert( InputIterator first, InputIterator last )
		{
			_tree.insert(first, last);
		}

		/*
		** Removes from the map container a single element at a given position.
		** This effectively reduces the container size by the number
		** of elements removed, which are destroyed.
		*/

		void erase( iterator position )
		{
			_tree.erase(position);
		}

		/*
		** Removes from the map container a single element
		** whose match with a given key.
		** This effectively reduces the container size by the number
		** of elements removed, which are destroyed.
		*/

		size_type erase( const key_type& key )
		{
			return (_tree.erase(key));
		}

		/*
		** Removes from the map container a range of elements.
		** This effectively reduces the container size by the number
		** of elements removed, which are destroyed.
		*/

		void erase( iterator first, iterator last )
		{
			_tree.erase(first, last);
		}

		/*
		** Exchanges the content of the container by the content of x
		** which is another map of the same type. Sizes may differ.
		*/

		void swap( map& other )
		{
			map tmp = *this;
			
			*this = other;
			other = tmp;
		}

		/*
		** Removes all elements from the map container (which are destroyed),
		** leaving the container with a size of 0.
		*/

		void clear( void )
		{
			_tree.clear();
		}

		/*
		** Returns a copy of the comparison object used
		** by the container to compare keys.
		*/

		key_compare key_comp( void ) const
		{
			return (_tree.key_comp());
		}

		/*
		** Returns a comparison object that can be used to compare two elements
		**to get whether the key of the first one goes before the second.
		*/

		value_compare value_comp( void ) const
		{
			return (value_compare(key_compare()));
		}

		/*
		** Searches the container for an element with a key equivalent to k
		** and returns an iterator to it if found,
		** otherwise it returns an iterator to map::end.
		*/

		iterator find( const key_type& key )
		{
			return (_tree.find(key));
		}

		/*
		** Searches the container for an element with a key equivalent to k
		** and returns a constiterator to it if found,
		** otherwise it returns an iterator to map::end.
		*/

		const_iterator find( const key_type& key ) const
		{
			return (_tree.find(key));
		}

		/*
		** Searches the container for elements with a key equivalent to k
		** and returns the number of matches.
		** 0 or 1 in the case of map.
		*/

		size_type count( const key_type& key ) const
		{
			return (_tree.count(key));
		}

		/*
		** Returns an iterator pointing to the first element
		** in the container whose key is not considered to go before key.
		*/

		iterator lower_bound( const key_type& key )
		{
			return (_tree.lower_bound(key));
		}

		/*
		** Returns a const iterator pointing to the first element
		** in the container whose key is not considered to go before key.
		*/

		const_iterator lower_bound( const key_type& key ) const
		{
			return (_tree.lower_bound(key));
		}

		/*
		** Returns an iterator pointing to the first element
		** in the container whose key is considered to go after key.
		*/

		iterator upper_bound( const key_type& key )
		{
			return (_tree.upper_bound(key));
		}

		/*
		** Returns a const iterator pointing to the first element
		** in the container whose key is considered to go after key.
		*/

		const_iterator upper_bound( const key_type& key ) const
		{
			return (_tree.upper_bound(key));
		}

		/*
		** Returns the bounds of a rang of iterators that includes all
		** the elements in the container which have a key equivalent to key.
		*/

		ft::pair<iterator, iterator> equal_range( const key_type& key )
		{
			return (_tree.equal_range(key));
		}

		/*
		** Returns the bounds of a rang of const iterators that includes all
		** the elements in the container which have a key equivalent to key.
		*/

		ft::pair<const_iterator, const_iterator>
			equal_range( const key_type& key ) const
		{
			return (_tree.equal_range(key));
		}

		/*
		** Returns a copy of the allocator object associated with the map.
		*/

		allocator_type get_allocator( void ) const
		{
			return (allocator_type(_tree.get_allocator()));
		}

	protected:

		tree_type	_tree;

	}; // class map

	/*
	** Performs the appropriate comparison operation between
	** the map containers lhs (x) and rhs (y).
	*/

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool operator==( const map<Key, T, Compare, Alloc>& x,
		const map<Key, T, Compare, Alloc>& y )
	{
		return ((x.size() == y.size()) &&
			ft::equal(x.begin(), x.end(), y.begin()));
	}

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool operator<( const map<Key, T, Compare, Alloc>& x,
		const map<Key, T, Compare, Alloc>& y )
	{
		return (ft::lexicographical_compare(x.begin(), x.end(),
			y.begin(), y.end()));
	}

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool operator!=( const map<Key, T, Compare, Alloc>& x,
		const map<Key, T, Compare, Alloc>& y )
	{
		return (!(x == y));
	}

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool	operator>( const map<Key, T, Compare, Alloc>& x,
		const map<Key, T, Compare, Alloc>& y )
	{
		return (y < x);
	}

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool operator<=( const map<Key, T, Compare, Alloc>& x,
		const map<Key, T, Compare, Alloc>& y )
	{
		return (!(y < x));
	}

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool operator>=( const map<Key, T, Compare, Alloc>& x,
		const map<Key, T, Compare, Alloc>& y )
	{
		return (!(x < y));
	}

	/*
	** The contents of container x are exchanged with those of y.
	** Both container objects must be of the same type,
	** although sizes may differ.
	*/

	template<typename Key, typename T, typename Compare, typename Alloc>
	void swap( map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y )
	{
		x.swap(y);
	}
	
} // namespace ft

#endif
