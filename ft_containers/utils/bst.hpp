/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 16:38:22 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/03 15:51:24 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_H
#define BST_H

#include "less.hpp"
#include "../iterators/iteratorTraits.hpp"
#include "../iterators/bstIterator.hpp"
#include "../iterators/reverseIterator.hpp"
#include <memory>

namespace ft
{

	template<typename Key, typename T, typename Compare = ft::less<Key>, typename Alloc = std::allocator<T> >
	class binarySearchTree
	{
		
		public:

		typedef Key											key_type;
		typedef T											value_type;
		typedef Compare										key_compare;
		typedef Alloc										allocator_type;
		typedef binarySearchTree<value_type>				node_type;
		typedef binarySearchTree<value_type>*				node_pointer;
		typedef value_type&									reference;
		typedef value_type const&							const_reference;
		typedef value_type*									pointer;
		typedef value_type const*							const_pointer;
		typedef ft::bstIterator<node_type>					iterator;
		typedef ft::bstIterator<node_type const>			const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef std::ptrdiff_t								difference_type;
		typedef std::size_t									size_type;
	}; // class binarySearchTree





} // namespace ft

#endif