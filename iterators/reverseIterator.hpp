/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:04:23 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/10 16:44:27 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITERATOR_HPP
#define REVERSEITERATOR_HPP

#include "iteratorTraits.hpp"
#include "typeTraits.hpp"

namespace ft
{

	template<typename Iterator>
	class reverseIterator
    : public iterator<typename iteratorTraits<Iterator>::iterator_category,
		typename iteratorTraits<Iterator>::value_type,
		typename iteratorTraits<Iterator>::difference_type,
		typename iteratorTraits<Iterator>::pointer,
        typename iteratorTraits<Iterator>::reference>
	{

		protected:
      		Iterator _current;
			typedef iteratorTraits<Iterator>		traitsType;

		public:

      		typedef Iterator								iterator_type;
      		typedef typename traitsType::difference_type	difference_type;
      		typedef typename traitsType::pointer			pointer;
      		typedef typename traitsType::reference			reference;

			reverseIterator( void ) : _current()
			{
				return ;
			};

			reverseIterator( Iterator it ) : _current(it)
			{
				return ;
			}

			reverseIterator( const reverseIterator & it )
				: _current(it._current)
			{
				return ;
			}

			template<typename Iter>
			reverseIterator( const reverseIterator<Iter> & it )
				: _current(it.base())
			{
				return ;
			}

			iterator_type base( void ) const
      		{
				return _current;
			}

			reference	operator*( void ) const
      		{
				Iterator tmp = _current;
				return *--tmp;
      		}

			pointer	operator->( void ) const
      		{
				return &(operator*());
      		}

			reverseIterator & operator++( void )
      		{
				--_current;
				return *this;
      		}

			reverseIterator	operator++( int )
      		{
				reverseIterator tmp = *this;
				
				--_current;
				return tmp;
      		}

			reverseIterator & operator--( void )
      		{
				++_current;
				return *this;
      		}

			reverseIterator	operator--( int )
      		{
				reverseIterator tmp = *this;
				
				++_current;
				return tmp;
      		}

			reverseIterator	operator+( difference_type n ) const
      		{
				return reverseIterator(_current - n);
			}

			reverseIterator &	operator+=( difference_type n )
      		{
				_current -= n;
				return *this;
      		}

			reverseIterator	operator-( difference_type n ) const
      		{
				return reverseIterator(_current + n);
			}

			reverseIterator &	operator-=( difference_type n )
      		{
				_current += n;
				return *this;
      		}

			reference	operator[]( difference_type n ) const
      		{
				return *(*this + n);
			}
	};

	template<typename Iterator>
    bool	operator==( const reverseIterator<Iterator>& lhs,
	    const reverseIterator<Iterator>& rhs )
    {
		return lhs.base() == rhs.base();
	}

	template<typename Iterator>
    bool	operator<( const reverseIterator<Iterator>& lhs,
	    const reverseIterator<Iterator>& rhs )
    {
		return lhs.base() < rhs.base();
	}

	template<typename Iterator>
    bool	operator!=( const reverseIterator<Iterator>& lhs,
	    const reverseIterator<Iterator>& rhs )
    {
		return lhs.base() != rhs.base();
	}

	template<typename Iterator>
    bool	operator>( const reverseIterator<Iterator>& lhs,
	    const reverseIterator<Iterator>& rhs )
    {
		return lhs.base() > rhs.base();
	}

	template<typename Iterator>
    bool	operator<=( const reverseIterator<Iterator>& lhs,
	    const reverseIterator<Iterator>& rhs )
    {
		return lhs.base() <= rhs.base();
	}

	template<typename Iterator>
    bool	operator>=( const reverseIterator<Iterator>& lhs,
	    const reverseIterator<Iterator>& rhs )
    {
		return lhs.base() >= rhs.base();
	}

	template<typename IteratorL, typename IteratorR>
    bool	operator==( const reverseIterator<IteratorL>& lhs,
	    const reverseIterator<IteratorR>& rhs )
    {
		return lhs.base() == rhs.base();
	}

	template<typename IteratorL, typename IteratorR>
    bool	operator<( const reverseIterator<IteratorL>& lhs,
	    const reverseIterator<IteratorR>& rhs )
    {
		return lhs.base() > rhs.base();
	}

	template<typename IteratorL, typename IteratorR>
    bool	operator!=( const reverseIterator<IteratorL>& lhs,
	    const reverseIterator<IteratorR>& rhs )
    {
		return lhs.base() != rhs.base();
	}

	template<typename IteratorL, typename IteratorR>
    bool	operator>( const reverseIterator<IteratorL>& lhs,
	    const reverseIterator<IteratorR>& rhs )
    {
		return lhs.base() < rhs.base();
	}

	template<typename IteratorL, typename IteratorR>
    bool	operator<=( const reverseIterator<IteratorL>& lhs,
	    const reverseIterator<IteratorR>& rhs )
    {
		return lhs.base() >= rhs.base();
	}

	template<typename IteratorL, typename IteratorR>
    bool	operator>=( const reverseIterator<IteratorL>& lhs,
	    const reverseIterator<IteratorR>& rhs )
    {
		return lhs.base() <= rhs.base();
	}

	template<typename Iterator>
    typename reverseIterator<Iterator>::difference_type
    operator-( const reverseIterator<Iterator>& x,
		const reverseIterator<Iterator>& y )
    {
		return y.base() - x.base();
	}

	template<typename IteratorL, typename IteratorR>
    typename reverseIterator<IteratorL>::difference_type
    operator-( const reverseIterator<IteratorL>& x,
		const reverseIterator<IteratorR>& y )
    {
		return y.base() - x.base();
	}

	template<typename Iterator>
    reverseIterator<Iterator>
    operator+( typename reverseIterator<Iterator>::difference_type n,
	    const reverseIterator<Iterator>& x )
    {
		return reverseIterator<Iterator>(x.base() - n);
	}

} // namespace ft

#endif