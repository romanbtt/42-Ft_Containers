#ifndef RBTREEITERATOR_H
# define RBTREEITERATOR_H

# include "../iterators/iterator_traits.hpp"

namespace ft
{

	template <typename T>
	class RBTreeIterator
	{

	public:
		
		typedef T										value_type;
		typedef value_type*								node_pointer;
		typedef typename T::value_type const			data_type;
		typedef data_type&								reference;
		typedef data_type const&						const_reference;
		typedef data_type*								pointer;
		typedef data_type const*						const_pointer;

		typedef typename std::ptrdiff_t					difference_type;
		typedef ft::bidirectional_iterator_tag			iterator_category;

		public:

			RBTreeIterator( void ): _ptr(NULL), _root(NULL), _null(NULL)
			{
				return ;
			};

			explicit RBTreeIterator( node_pointer ptr, node_pointer root, node_pointer null )
				: _ptr(ptr), _root(root), _null(null)
			{
				return ;
			};

			RBTreeIterator( const RBTreeIterator& src )
				: _ptr(src._ptr), _root(src._root), _null(src._null)
			{
				return ;
			};

			virtual ~RBTreeIterator()
			{
				return ;
			}

			RBTreeIterator &operator=( const RBTreeIterator& rhs )
			{
				if (this != &rhs)
				{
					_ptr = rhs._ptr;
					_root = rhs._root;
					_null = rhs._null;
				}
				return *this;
			}

			operator RBTreeIterator<value_type const>() const
			{
				return RBTreeIterator<value_type const>(_ptr, _root, _null);
			}

			reference operator*( void )
			{
				return _ptr->content;
			}

			const_reference operator*( void ) const
			{
				return _ptr->content;
			}

			pointer operator->( void )
			{
				return &(operator*());
			}

			bool operator==( const RBTreeIterator& rhs ) const
			{
				return (_ptr == rhs._ptr);
			}

			bool operator!=( const RBTreeIterator& rhs ) const
			{
				return (_ptr != rhs._ptr);
			}

			RBTreeIterator& operator++( void )
			{
				if (_ptr != _null)
					_ptr = _get_successor(_ptr);

				return *this;
			}

			RBTreeIterator operator++( int )
			{
				RBTreeIterator tmp(*this);
				operator++();
				return tmp;
			}

			RBTreeIterator& operator--( void)
			{
				if (_ptr == _null)
					_ptr = _maximum(_root);
				else
					_ptr = _get_predecessor(_ptr);
				return *this;
			}

			RBTreeIterator operator--( int )
			{
				RBTreeIterator tmp(*this);
				operator--();
				return tmp;
			}

			node_pointer get_node( void )
			{
				return _ptr;
			}

			node_pointer successor( node_pointer node )
			{
				return _get_successor(node);
			}
		
		private:

			node_pointer _maximum( node_pointer node )
			{
				while (node->right != _null)
					node = node->right;
				return node;
			}

			node_pointer _minimum( node_pointer node )
			{
				while (node->left != _null && node != _null)
					node = node->left;
				return node;
			}

			node_pointer _get_predecessor( node_pointer node )
			{
				node_pointer predecessor;

				if (node->left != _null)
					return _maximum(node->left);
				predecessor = node->parent;
				while (node->parent != NULL && node == predecessor->left)
				{
					node = predecessor;
					predecessor = predecessor->parent;
				}
				if (!predecessor)
					return _null;
				else
					return predecessor;
			}

			node_pointer _get_successor( node_pointer node )
			{
				node_pointer successor;

				if (node == _null)
					return (_null);
				if (node->right != _null)
					return _minimum(node->right);
				successor = node->parent;
				while (node->parent != NULL && node == successor->right)
				{
					node = successor;
					successor = successor->parent;
				}
				if (!successor)
					return _null;
				else
					return successor;
			}
		
		protected:

			node_pointer	_ptr;
			node_pointer	_root;
			node_pointer	_null;
	};
} // namespace ft

#endif
