/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:37:19 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/22 12:11:27 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_H
#define RBTREE_H

# include <memory>
# include "less.hpp"
# include "pair.hpp"
# include "../iterators/rb_tree_iterator.hpp"


namespace ft
{

	enum rbt_color_node
	{
		BLACK,
		RED
	};

	template<typename Key, typename T>
	struct rbt_node
	{
		typedef ft::pair<Key, T>						value_type;

		value_type		content;
		rbt_node*		parent;
		rbt_node*		left;
		rbt_node*		right;
		rbt_color_node	color;

		rbt_node( value_type content ) : content(content)
		{
			return ;
		}
	};

	template<typename Key, typename T, typename Compare = ft::less<Key>,
		typename Alloc = std::allocator<ft::pair<const Key, T> > >
	class RBTree
	{

	public:
		typedef Key										key_type;
		typedef T										mapped_type;
		typedef Compare									key_compare;
		typedef rbt_node<key_type, mapped_type>			node_type;
		typedef ft::RBTreeIterator<node_type>			iterator;
		typedef ft::RBTreeIterator<const node_type>		const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef node_type*								pointer;
		typedef const node_type*						const_pointer;
		typedef node_type&								reference;
		typedef const node_type&						const_reference;
		typedef ft::pair<const Key, T>					value_type;
		typedef typename Alloc::template rebind
			<rbt_node<key_type, mapped_type> >::other	allocator_type;
		typedef size_t									size_type;

		explicit RBTree( const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type() )
			: _root(NULL), _end(NULL), _alloc(alloc), _compare(comp), _size(0)
		{
			_end = _alloc.allocate(1);
			_alloc.construct(_end, node_type(value_type()));
			_end->color = BLACK;
			_root = _end;
		}

		template<typename InputIterator>
		RBTree( InputIterator first, InputIterator last,
				key_compare const& comp = key_compare(),
				allocator_type const& alloc = allocator_type() )
				: _root(NULL), _end(NULL), _alloc(alloc), _compare(comp), _size(0)
		{
			_end = _alloc.allocate(1);
			_alloc.construct(_end, node_type(value_type()));
			_end->color = BLACK;
			_root = _end;
			insert(first, last);
		}

		RBTree( RBTree const &src )
			: _root(NULL), _end(NULL), _alloc(src._alloc), _compare(src._compare), _size(0)
		{
			_end = _alloc.allocate(1);
			_alloc.construct(_end, node_type(value_type()));
			_end->color = BLACK;
			_root = _end;
			*this = src;
		}

		virtual	~RBTree( void )
		{
			clear();
			_alloc.destroy(_end);
			_alloc.deallocate(_end, 1);
		};

		RBTree&	operator=( RBTree const &rhs )
		{
			if (this != &rhs)
			{
				clear();
				_alloc = rhs._alloc;
				_compare = rhs._compare;
				insert(rhs.begin(), rhs.end());
			}
			return *this;
		}

		iterator	begin( void)
		{
			return (iterator(_minimum(_root), _root, _end));
		}

		const_iterator	begin( void ) const
		{
			return (const_iterator(_minimum(_root), _root, _end));
		};
		
		iterator	end( void )
		{
			return (iterator(_end, _root, _end));
		}

		const_iterator	end( void ) const
		{
			return (const_iterator(_end, _root, _end));
		};

		reverse_iterator	rbegin( void )
		{
			return (reverse_iterator(end()));
		}

		const_reverse_iterator	rbegin() const
		{
			return (const_reverse_iterator(end()));
		};

		reverse_iterator	rend( void )
		{
			return (reverse_iterator(begin()));
		}

		const_reverse_iterator	rend( void ) const
		{
			return (const_reverse_iterator(begin()));
		};

		bool	empty( void ) const
		{
			if (_root == _end)
				return true;
			return false;
		}

		size_type	size( void ) const
		{
			return _size;
		}

		size_type	max_size( void ) const
		{
			return _alloc.max_size();
		}

		mapped_type&	operator[]( const key_type& key )
		{
			iterator it = find(key);

			if (it == end() || key_comp()(key, (*it).first))
	  			it = insert(it, value_type(key, mapped_type()));
			return it.get_node()->content.second;
		}

		ft::pair<iterator, bool>	insert( const value_type& val )
      	{
			iterator it = find(val.first);

			if (it != end())
				return ft::make_pair(it, false);
			pointer node = _alloc.allocate(1);
			_alloc.construct(node, node_type(val));
			pointer node_inserted = _insertNode(node, _root);
			it = iterator(node_inserted, _root, _end);
			_size++;
			return ft::make_pair(it, true);		
		}

		iterator	insert( iterator position, const value_type& val )
      	{
			pointer succ = position.successor(position.get_node());

			if (_compare(position->first, val.first) &&
				_compare(val.first, succ->content.first))
			{
				pointer node = _alloc.allocate(1);
				_alloc.construct(node, node_type(val));
				pointer node_inserted = _insertNode(node, position.get_node());
				_size++;
				return iterator(node_inserted, _root, _end);
			}
			else
				return insert(val).first;
		}

		template<typename InputIterator>
		void	insert( InputIterator first, InputIterator last )
		{
			while (first != last)
				insert(*first++);
		}

		void	erase( iterator position )
		{
			if (position == end())
				return;
			_eraseNode(position.get_node());
			_size--;
		}

		size_type	erase( const key_type& key )
		{
			iterator it = find(key);
			if (it == end())
				return (0);
			erase(it);
			return (1);
		}

		void	erase( iterator first, iterator last )
		{
			while (first != last)
				erase(first++);
		}

		void	clear( void )
		{
			_clear(_root);
			_root = _end;
		}

		key_compare	key_comp( void ) const
		{
			return key_compare();
		}

		iterator	find( const key_type& key )
		{
			iterator it = _find(key, _root);
			
			return it;
		}

		const_iterator	find( const key_type& key ) const
		{
			const_iterator it = _find(key, _root);

			return it;
		}

		size_type	count( const key_type& key ) const
		{
			if (find(key) != end())
				return (1);
			return (0);
		}

		iterator	lower_bound( const key_type& key )
		{
			for (iterator it = begin(); it != end(); it++)
			{
				if (!(_compare(it.get_node()->content.first, key)))
					return it;
			}
			return (end());
		}

		const_iterator	lower_bound( const key_type& key ) const
		{
			for (const_iterator it = begin(); it != end(); it++)
			{
				if (!(_compare(it.get_node()->content.first, key)))
					return it;
			}
			return (end());
		}

		iterator	upper_bound( const key_type& key )
		{
			for (iterator it = begin(); it != end(); it++)
			{
				if (_compare(key, it.get_node()->content.first))
					return it;
			}
			return (end());
		}

		const_iterator	upper_bound( const key_type& key ) const
		{
			for (const_iterator it = begin(); it != end(); it++)
			{
				if (_compare(key, it.get_node()->content.first))
					return it;
			}
			return (end());
		}

		ft::pair<iterator,iterator>	equal_range( const key_type& key )
		{
			return ft::pair<iterator, iterator>(lower_bound(key),
				upper_bound(key));
		}

		ft::pair<const_iterator, const_iterator>
			equal_range( const key_type& key ) const
		{
			return ft::pair<const_iterator, const_iterator>(lower_bound(key),
				upper_bound(key));
		}

		Alloc	get_allocator( void ) const
		{
			return (Alloc(_alloc));
		}
 
	private:

		pointer			_root;
		pointer			_end; 
		allocator_type	_alloc;
		key_compare		_compare;
		size_type		_size;

		pointer	_insertNode( pointer new_node, pointer from )
		{
			pointer y = _end;
			pointer x = from;

			while (x != _end)
			{
				y = x;
				if (_compare(new_node->content.first, x->content.first))
					x = x->left;
				else
					x = x->right;
			}
			new_node->parent = y;
			if (y == _end)
				_root = new_node;
			else if (_compare(new_node->content.first, y->content.first))
				y->left = new_node;
			else
				y->right = new_node;
			new_node->left = _end;
			new_node->right = _end;
			new_node->color = RED;
			_insertFixUp(new_node);
			return (new_node);
		}

		void	_insertFixUp( pointer node )
		{
			pointer uncle;

			while (node->parent->color == RED)
			{
				if (node->parent == node->parent->parent->left)
				{
					uncle = node->parent->parent->right;
					if (uncle->color == RED)
					{
						node->parent->color = BLACK;
						uncle->color = BLACK;
						node->parent->parent->color = RED;
						node = node->parent->parent;
					}
					else if(node == node->parent->right)
					{
						node = node->parent;
						_left_rotate(node);
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						_right_rotate(node->parent->parent);
					}
					else
					{
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						_right_rotate(node->parent->parent);
					}

				}
				else
				{
					uncle = node->parent->parent->left;
					if (uncle->color == RED)
					{
						node->parent->color = BLACK;
						uncle->color = BLACK;
						node->parent->parent->color = RED;
						node = node->parent->parent;
					}
					else if(node == node->parent->left)
					{
						node = node->parent;
						_right_rotate(node);
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						_left_rotate(node->parent->parent);
					}
					else
					{
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						_left_rotate(node->parent->parent);
					}
				}
			}
			_root->color = BLACK;
		}
		
		void	_left_rotate( pointer node )
		{
			pointer new_parent = node->right;

			node->right = new_parent->left;
			if (new_parent->left != _end)
				new_parent->left->parent = node;
			new_parent->parent = node->parent;
			if (node->parent == _end)
				_root = new_parent;
			else if (node == node->parent->left)
				node->parent->left = new_parent;
			else
				node->parent->right = new_parent;
			new_parent->left = node;
			node->parent = new_parent;
		}

		void	_right_rotate( pointer node )
		{
			pointer new_parent = node->left;

			node->left = new_parent->right;
			if (new_parent->right != _end)
				new_parent->right->parent = node;
			new_parent->parent = node->parent;
			if (node->parent == _end)
				_root = new_parent;
			else if (node == node->parent->left)
				node->parent->left = new_parent;
			else
				node->parent->right = new_parent;
			new_parent->right = node;
			node->parent = new_parent;
		}

		pointer	_minimum( pointer node )
		{
			while (node->left != _end && node != _end)
				node = node->left;
			return node;
		}

		pointer	_minimum( pointer node ) const
		{
			while (node->left != _end)
				node = node->left;
			return node;
		}

		void _clear( pointer node )
		{
			if (node == _end)
				return ;
			_clear(node->left);
			_clear(node->right);
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
			_size--;
		}

		iterator	_find( const key_type& key, const pointer& node ) const
		{
			if (node == _end)
				return iterator(_end, _root, _end);
			else if (node->content.first == key )
				return iterator(node, _root, _end);
			if (_compare(node->content.first, key))
				return _find(key, node->right);
			else
				return _find(key, node->left);
		}

		void	_eraseNode( pointer z )
		{
			pointer x = NULL;
			pointer y = z;
			rbt_color_node y_orginal_color = y->color;

			if (z->left == _end)
			{
				x = z->right;
				_transplant(z, z->right);
			}
			else if (z->right == _end)
			{
				x = z->left;
				_transplant(z, z->left);
			}
			else
			{
				y = _minimum(z->right);
				y_orginal_color = y->color;
				x = y->right;
				if (y->parent == z)
					x->parent = y;
				else
				{
					_transplant(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}
				_transplant(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color;
			}
			if (y_orginal_color == BLACK)
				_deleteFixUp(x);
			_destroyNode(z);
		}

		void	_deleteFixUp( pointer x )
		{
			pointer w;
			
			while (x != _root && x->color == BLACK)
			{
				if (x == x->parent->left)
				{
					w = x->parent->right;
					if (w->color == RED)
					{
						w->color = BLACK;
						x->parent->color = RED;
						_left_rotate(x->parent);
						w = x->parent->right;
					}
					if (w->left->color == BLACK && w->right->color == BLACK)
					{
						w->color = RED;
						x = x->parent;
					}
					else if (w->right->color == BLACK)
					{
						w->left->color = BLACK;
						w->color = RED;
						_right_rotate(w);
						w = x->parent->right;
						w->color = x->parent->color;
						x->parent->color = BLACK;
						w->right->color = BLACK;
						_left_rotate(x->parent);
						x = _root;
					}
					else
					{
						w->color = x->parent->color;
						x->parent->color = BLACK;
						w->right->color = BLACK;
						_left_rotate(x->parent);
						x = _root;
					}
				}
				else
				{
					w = x->parent->left;
					if (w->color == RED)
					{
						w->color = BLACK;
						x->parent->color = RED;
						_right_rotate(x->parent);
						w = x->parent->left;
					}
					if (w->right->color == BLACK && w->left->color == BLACK)
					{
						w->color = RED;
						x = x->parent;
					}
					else if (w->left->color == BLACK)
					{
						w->right->color = BLACK;
						w->color = RED;
						_left_rotate(w);
						w = x->parent->left;
						w->color = x->parent->color;
						x->parent->color = BLACK;
						w->left->color = BLACK;
						_right_rotate(x->parent);
						x = _root;
					}
					else
					{
						w->color = x->parent->color;
						x->parent->color = BLACK;
						w->left->color = BLACK;
						_right_rotate(x->parent);
						x = _root;
					}
				}
				x->color = BLACK;
			}
		}

		void	_transplant( pointer u, pointer v )
		{
			if (u->parent == _end)
				_root = v;
			else if (u == u->parent->left)
				u->parent->left = v;
			else
				u->parent->right = v;
			v->parent = u->parent;
		}

		void	_destroyNode( pointer node )
		{
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
		}

	};

} // namespace ft

#endif
