/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:45:48 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/21 14:49:55 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include "../utils/less.hpp"
#include "../utils/pair.hpp"
#include "../utils/rb_tree.hpp"
# include "../iterators/iterator_traits.hpp"
#include <memory>

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
		};
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

			explicit map( const Compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type() )
				: _tree(comp, allocator_type(alloc))
			{
				return ;
			}

			template<typename InputIterator>
			map( InputIterator first, InputIterator last,
				const Compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type() )
				: _tree(comp, allocator_type(alloc))
			{
				_tree.insert(first, last);
			}

			map( const map& src ) : _tree(src._tree)
			{
				return ;
			}

			virtual ~map( void )
			{
				clear();
			}

			map	&operator=( const map& rhs )
			{
				_tree = rhs._tree;
				return (*this);
			}

			iterator begin( void )
			{
				return (_tree.begin());
			}

			const_iterator begin( void ) const
			{
				return (_tree.begin());
			}

			iterator end( void )
			{
				return (_tree.end());
			}

			const_iterator end( void ) const
			{
				return (_tree.end());
			}

			reverse_iterator rbegin( void )
			{
				return (_tree.rbegin());
			}

			const_reverse_iterator rbegin( void ) const
			{
				return (_tree.rbegin());
			}

			reverse_iterator rend( void )
			{
				return (_tree.rend());
			}

			const_reverse_iterator rend( void ) const
			{
				return (_tree.rend());
			}

			bool empty( void ) const
			{
				return (_tree.empty());
			}

			size_type size( void ) const
			{
				return (_tree.size());
			}

			size_type max_size( void ) const
			{
				return (_tree.max_size());
			}

			mapped_type &operator[]( const key_type& key )
			{
				return (_tree[key]);
			}

			ft::pair<iterator, bool> insert( const value_type& val )
			{
				return (_tree.insert(val));
			}

			iterator insert( iterator position, const value_type& val )
			{
				return (_tree.insert(position, val));
			}

			template<typename InputIterator>
			void insert( InputIterator first, InputIterator last )
			{
				_tree.insert(first, last);
			}

			void erase( iterator position )
			{
				_tree.erase(position);
			}

			size_type erase( const key_type& key )
			{
				return (_tree.erase(key));
			}

			void erase( iterator first, iterator last )
			{
				_tree.erase(first, last);
			}

			void swap( map& other )
			{
				map tmp = *this;
				
				*this = other;
				other = tmp;
			}

			void clear( void )
			{
				_tree.clear();
			}

			key_compare key_comp( void ) const
			{
				return (_tree.key_comp());
			}

			value_compare value_comp( void ) const
			{
				return (value_compare(key_compare()));
			}

			iterator find( const key_type& key )
			{
				return (_tree.find(key));
			}

			const_iterator find( const key_type& key ) const
			{
				return (_tree.find(key));
			}

			size_type count( const key_type& key ) const
			{
				return (_tree.count(key));
			}

			iterator lower_bound( const key_type& key )
			{
				return (_tree.lower_bound(key));
			}

			const_iterator lower_bound( const key_type& key ) const
			{
				return (_tree.lower_bound(key));
			}

			iterator upper_bound( const key_type& key )
			{
				return (_tree.upper_bound(key));
			}

			const_iterator upper_bound( const key_type& key ) const
			{
				return (_tree.upper_bound(key));
			}

			ft::pair<iterator, iterator> equal_range( const key_type& key )
			{
				return (_tree.equal_range(key));
			}

			ft::pair<const_iterator, const_iterator>
				equal_range( const key_type& key ) const
			{
				return (_tree.equal_range(key));
			}

			allocator_type get_allocator( void ) const
			{
				return (allocator_type(_tree.get_allocator()));
			}

		private:

			tree_type	_tree;

	};

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

	template<typename Key, typename T, typename Compare, typename Alloc>
	void swap( map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y )
	{
		x.swap(y);
	}
	
} // namespace ft

#endif
