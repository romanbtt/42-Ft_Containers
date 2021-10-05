/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bstIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 20:48:05 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/03 15:22:53 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_ITERATOR_H
#define BST_ITERATOR_H

#include "iteratorTraits.hpp"
#include "../utils/bst.hpp"

namespace ft
{

	template <typename T>
    class bstIterator
    {

        public :
            
            typedef T							value_type;
			typedef T&							reference;
			typedef T*							pointer;
			typedef bidirectional_iterator_tag	iterator_category;
			typedef typename std::ptrdiff_t		difference_type;
			typedef bstIterator<T>       		self;

		bstIterator( void ) : _node()
		{
			return ;
		}

		bstIterator( pointer node ) : _node(node)
		{
			return ;
		}

		bstIterator( const bstIterator& src ) : _node(src._node)
		{
			return ;
		}

		virtual ~bstIterator()
		{
			return ;
		}

		bstIterator &operator=( const bstIterator& rhs )
		{
			if (*this != rhs)
			{
				_node = rhs._node;
			}
			return (*this);
		}

		bool operator==( const bstIterator& rhs )
		{ 
			return _node == rhs._node;
		}

		bool operator!=( const bstIterator& rhs )
		{ 
			return _node != rhs._node;
		}

		reference operator*( void ) const
		{ 
			return _node->_value; 
		}

		pointer operator->( void ) const
		{ 
			return &_node->_value; 
		}

		bstIterator&	operator++( void )
		{
			if (_node->_right != 0)
      		{
        		_node = _node->_right;
        		while (_node->_left != 0)
          			_node = _node->_left;
			}
    		else
      		{
        		pointer tmp = _node->_parent;
        		while (_node ==	tmp->_right)
          		{
            		_node = tmp;
            		tmp = tmp->_parent;
          		}
        		if (_node->_right != tmp)
          			_node = tmp;
      		}
    		return *this;
  		}

		bstIterator operator++( int )
		{
			bstIterator tmp(*this);
			operator++();
			return (tmp);
		}

		bstIterator&	operator--( void )
  		{
			if (_node->_left != 0)
      		{
        		_node = _node->_left;
        		while (_node->_right != 0)
          			_node = _node->_right;
			}
    		else
      		{
        		pointer tmp = _node->_parent;
        		while (_node ==	tmp->_left)
          		{
            		_node = tmp;
            		tmp = tmp->_parent;
          		}
        		if (_node->_left != tmp)
          			_node = tmp;
      		}
    		return *this;
  		}

		bstIterator operator--( int )
		{
			bstIterator tmp(*this);
			operator--();
			return (tmp);
		}

		protected:

			pointer _node;
  
      };

	template <typename T>
    class bstConstIterator
    {

        public :
            
            typedef T							value_type;
			typedef T&							reference;
			typedef T*							pointer;
			typedef bidirectional_iterator_tag	iterator_category;
			typedef typename std::ptrdiff_t		difference_type;
			typedef bstConstIterator<T>       	self;

		bstConstIterator( void ) : _node()
		{
			return ;
		}

		bstConstIterator( pointer node ) : _node(node)
		{
			return ;
		}

		bstConstIterator( const bstIterator& src ) : _node(src._node)
		{
			return ;
		}

		virtual ~bstConstIterator()
		{
			return ;
		}

		bstConstIterator &operator=( const bstConstIterator& rhs )
		{
			if (*this != rhs)
			{
				_node = rhs._node;
			}
			return (*this);
		}

		bool operator==( const bstConstIterator& rhs )
		{ 
			return _node == rhs._node;
		}

		bool operator!=( const bstConstIterator& rhs )
		{ 
			return _node != rhs._node;
		}

		reference operator*( void ) const
		{ 
			return _node->_value; 
		}

		pointer operator->( void ) const
		{ 
			return &_node->_value; 
		}

		bstConstIterator&	operator++( void )
		{
			if (_node->_right != 0)
      		{
        		_node = _node->_right;
        		while (_node->_left != 0)
          			_node = _node->_left;
			}
    		else
      		{
        		pointer tmp = _node->_parent;
        		while (_node ==	tmp->_right)
          		{
            		_node = tmp;
            		tmp = tmp->_parent;
          		}
        		if (_node->_right != tmp)
          			_node = tmp;
      		}
    		return *this;
  		}

		bstConstIterator operator++( int )
		{
			bstIterator tmp(*this);
			operator++();
			return (tmp);
		}

		bstConstIterator&	operator--( void )
  		{
			if (_node->_left != 0)
      		{
        		_node = _node->_left;
        		while (_node->_right != 0)
          			_node = _node->_right;
			}
    		else
      		{
        		pointer tmp = _node->_parent;
        		while (_node ==	tmp->_left)
          		{
            		_node = tmp;
            		tmp = tmp->_parent;
          		}
        		if (_node->_left != tmp)
          			_node = tmp;
      		}
    		return *this;
  		}

		bstConstIterator operator--( int )
		{
			bstIterator tmp(*this);
			operator--();
			return (tmp);
		}

		protected:

			pointer _node;
  
      };
} // namespace ft

#endif