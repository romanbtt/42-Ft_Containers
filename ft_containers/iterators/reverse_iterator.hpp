/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:04:23 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/10 16:44:27 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef reverse_iterator_H
#define reverse_iterator_H

# include "iterator_traits.hpp"
# include "type_traits.hpp"

namespace ft
{

	template<typename Iterator>
	class reverse_iterator
    : public iterator<typename iterator_traits<Iterator>::iterator_category,
		typename iterator_traits<Iterator>::value_type,
		typename iterator_traits<Iterator>::difference_type,
		typename iterator_traits<Iterator>::pointer,
        typename iterator_traits<Iterator>::reference>
	{

		protected:
      		Iterator _current;
			typedef iterator_traits<Iterator>		traitsType;

		public:

      		typedef Iterator								iterator_type;
      		typedef typename traitsType::difference_type	difference_type;
      		typedef typename traitsType::pointer			pointer;
      		typedef typename traitsType::reference			reference;

			reverse_iterator( void ) : _current()
			{
				return ;
			};

			explicit reverse_iterator( iterator_type it ) : _current(it)
			{
				return ;
			}

			reverse_iterator( const reverse_iterator & it )
				: _current(it._current)
			{
				return ;
			}

			template<typename Iter>
			reverse_iterator( const reverse_iterator<Iter> & it )
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

			reverse_iterator & operator++( void )
      		{
				--_current;
				return *this;
      		}

			reverse_iterator	operator++( int )
      		{
				reverse_iterator tmp = *this;
				
				--_current;
				return tmp;
      		}

			reverse_iterator & operator--( void )
      		{
				++_current;
				return *this;
      		}

			reverse_iterator	operator--( int )
      		{
				reverse_iterator tmp = *this;
				
				++_current;
				return tmp;
      		}

			reverse_iterator	operator+( difference_type n ) const
      		{
				return reverse_iterator(_current - n);
			}

			reverse_iterator &	operator+=( difference_type n )
      		{
				_current -= n;
				return *this;
      		}

			reverse_iterator	operator-( difference_type n ) const
      		{
				return reverse_iterator(_current + n);
			}

			reverse_iterator &	operator-=( difference_type n )
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
    bool	operator==( const reverse_iterator<Iterator>& x,
	    const reverse_iterator<Iterator>& y )
    {
		return x.base() == y.base();
	}

	template<typename Iterator>
    bool	operator<( const reverse_iterator<Iterator>& x,
	    const reverse_iterator<Iterator>& y )
    {
		return y.base() < x.base();
	}

	template<typename Iterator>
    bool	operator!=( const reverse_iterator<Iterator>& x,
	    const reverse_iterator<Iterator>& y )
    {
		return !(x == y);
	}

	template<typename Iterator>
    bool	operator>( const reverse_iterator<Iterator>& x,
	    const reverse_iterator<Iterator>& y )
    {
		return y < x;
	}

	template<typename Iterator>
    bool	operator<=( const reverse_iterator<Iterator>& x,
	    const reverse_iterator<Iterator>& y )
    {
		return !(y < x);
	}

	template<typename Iterator>
    bool	operator>=( const reverse_iterator<Iterator>& x,
	    const reverse_iterator<Iterator>& y )
    {
		return !(x < y);
	}

	template<typename IteratorL, typename IteratorR>
    bool	operator==( const reverse_iterator<IteratorL>& x,
	    const reverse_iterator<IteratorR>& y )
    {
		return x.base() == y.base();
	}

	template<typename IteratorL, typename IteratorR>
    bool	operator<( const reverse_iterator<IteratorL>& x,
	    const reverse_iterator<IteratorR>& y )
    {
		return y.base() < x.base();
	}

	template<typename IteratorL, typename IteratorR>
    bool	operator!=( const reverse_iterator<IteratorL>& x,
	    const reverse_iterator<IteratorR>& y )
    {
		return !(x == y);
	}

	template<typename IteratorL, typename IteratorR>
    bool	operator>( const reverse_iterator<IteratorL>& x,
	    const reverse_iterator<IteratorR>& y )
    {
		return y < x;
	}

	template<typename IteratorL, typename IteratorR>
    bool	operator<=( const reverse_iterator<IteratorL>& x,
	    const reverse_iterator<IteratorR>& y )
    {
		return !(y < x);
	}

	template<typename IteratorL, typename IteratorR>
    bool	operator>=( const reverse_iterator<IteratorL>& x,
	    const reverse_iterator<IteratorR>& y )
    {
		return !(x < y);
	}

	template<typename Iterator>
    typename reverse_iterator<Iterator>::difference_type
    operator-( const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y )
    {
		return y.base() - x.base();
	}

	template<typename IteratorL, typename IteratorR>
    typename reverse_iterator<IteratorL>::difference_type
    operator-( const reverse_iterator<IteratorL>& x,
		const reverse_iterator<IteratorR>& y )
    {
		return y.base() - x.base();
	}

	template<typename Iterator>
    reverse_iterator<Iterator>
    operator+( typename reverse_iterator<Iterator>::difference_type n,
	    const reverse_iterator<Iterator>& x )
    {
		return reverse_iterator<Iterator>(x.base() - n);
	}

} // namespace ft

#endif
