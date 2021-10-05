/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:43:45 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/03 16:32:33 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

# include <memory>
# include <functional>
# include "../utils/less.hpp"
# include "../utils/pair.hpp"
# include "../iterators/typeTraits.hpp"

namespace ft
{
	template <class Key,
			  class T,
			  class Compare = ft::less<Key>,
			  class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{

		public:

			typedef typename Key											key_type;
			typedef	typename T												mapped_type;
			typedef	typename ft::pair<const Key, T>							value_type;
			typedef	typename Compare										key_compare;
			typedef typename Alloc  										allocator_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer     					pointer;
			typedef typename allocator_type::const_pointer 					const_pointer;
			typedef typename ft::binarySearchTree<value_type, key_compare>	tree_type;
			typedef typename tree_type::iterator 							iterator;
			typedef typename tree_type::const_iterator 						const_iterator;
			typedef typename tree_type::reverse_iterator 					reverse_iterator;
			typedef typename tree_type::const_reverse_iterator 				const_reverse_iterator;
			typedef std::ptrdiff_t											difference_type;
			typedef std::size_t 											size_type;

			class value_compare : public std::binary_function<value_type, value_type, bool>
			{

				friend class map<Key, T, Compare, Alloc>;

    			protected:

					Compare comp;

					value_compare( Compare c ) : comp(c)
					{
						return ;
					}

      			public:
					
					bool operator()( const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}

      		}; // class value_compare

			explicit	map( key_compare const& comp = key_compare(),
				allocator_type const& alloc = allocator_type())
				: _alloc(alloc), _comp(comp), _bst()
			{
				return ;
			}

			template <class InputIterator> 
			map( InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type(),
				typename ft::enableIf<!ft::isIntegral<InputIterator>::value,
				InputIterator>::type* = NULL ))
				: _alloc(alloc), _comp(comp), _bst()
			{
				insert(first, last);
			}

			map( const map& src ) : _alloc(src._alloc), _comp(src._comp), _bst(src._bst)
			{
				return ;
			}

			virtual	~map()
			{
				return ;
			}

			private:

				allocator_type	_alloc;
				key_compare		_comp;
				tree_type		_bst;



	}; // class map

} // namespace ft

#endif
