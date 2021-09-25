/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:04:23 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/25 13:53:13 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMACCESSITERATOR_HPP
#define RANDOMACCESSITERATOR_HPP

#include "iteratorTraits.hpp"
#include "typeTraits.hpp"

namespace ft
{

	template<typename Iterator, typename Container>
	class randomAccessIterator
	{
		protected:

			Iterator _current;
			typedef iteratorTraits<Iterator>				traitsType;

		public:
			
			typedef Iterator								iterator_type;
			typedef typename traitsType::iterator_category	iterator_category;
			typedef typename traitsType::value_type 		value_type;
			typedef typename traitsType::difference_type 	difference_type;
			typedef typename traitsType::reference 			reference;
			typedef typename traitsType::pointer 			pointer;

			randomAccessIterator() : _current(Iterator())
			{
				return ;
			}

			explicit randomAccessIterator( const Iterator & it ) : _current(it)
			{
				return ;
			}
			
      		template<typename Iter>
    		randomAccessIterator( const randomAccessIterator<Iter, typename ft::enableIf<
      	    (ft::isSame<Iter, typename Container::pointer>::value),
		    Container>::type>& it) : _current(it.base() )
			{
				return ;
			}

			reference	operator*( void ) const
      		{
				  return *_current;
			}

			pointer	operator->( void ) const
      		{
				  return _current;
			}

			randomAccessIterator & operator++( void )
      		{
				++_current;
				return *this;
      		}

			randomAccessIterator	operator++( int ) 
      		{
				return randomAccessIterator(_current++);
			}

			randomAccessIterator &	operator--( void )
      		{
				--_current;
				return *this;
      		}

			randomAccessIterator	operator--( int )
      		{
				return randomAccessIterator(_current--);
			}

			reference	operator[]( difference_type n ) const
      		{
				return _current[n];
			}

			randomAccessIterator & operator+=( difference_type n )
      		{
				_current += n;
				return *this;
			}

			randomAccessIterator	operator+( difference_type n ) const
      		{
				return randomAccessIterator(_current + n);
			}

			randomAccessIterator &	operator-=( difference_type n )
      		{
				_current -= n;
				return *this;
			}

			randomAccessIterator	operator-( difference_type n ) const
      		{
				return randomAccessIterator(_current - n);
			}

			const Iterator &	base( void ) const
      		{
				return _current;
			}
	};

	template<typename IteratorL, typename IteratorR, typename Container>
    bool	operator==( const randomAccessIterator<IteratorL, Container>& lhs,
	       const randomAccessIterator<IteratorR, Container>& rhs )
    {
		return lhs.base() == rhs.base();
	}

	template<typename Iterator, typename Container>
    bool	operator==( const randomAccessIterator<Iterator, Container>& lhs,
	       const randomAccessIterator<Iterator, Container>& rhs )
    {
		return lhs.base() == rhs.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	bool	operator!=( const randomAccessIterator<IteratorL, Container>& lhs,
	       const randomAccessIterator<IteratorR, Container>& rhs )
    {
		return lhs.base() != rhs.base();
	}

	template<typename Iterator, typename Container>
    bool	operator!=( const randomAccessIterator<Iterator, Container>& lhs,
	       const randomAccessIterator<Iterator, Container>& rhs )
    {
		return lhs.base() != rhs.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	bool	operator<( const randomAccessIterator<IteratorL, Container>& lhs,
	       const randomAccessIterator<IteratorR, Container>& rhs )
    {
		return lhs.base() < rhs.base();
	}

	template<typename Iterator, typename Container>
    bool	operator<( const randomAccessIterator<Iterator, Container>& lhs,
	       const randomAccessIterator<Iterator, Container>& rhs )
    {
		return lhs.base() < rhs.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	bool	operator>( const randomAccessIterator<IteratorL, Container>& lhs,
	       const randomAccessIterator<IteratorR, Container>& rhs )
    {
		return lhs.base() > rhs.base();
	}

	template<typename Iterator, typename Container>
    bool	operator>( const randomAccessIterator<Iterator, Container>& lhs,
	       const randomAccessIterator<Iterator, Container>& rhs )
    {
		return lhs.base() > rhs.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	bool	operator<=( const randomAccessIterator<IteratorL, Container>& lhs,
	       const randomAccessIterator<IteratorR, Container>& rhs )
    {
		return lhs.base() <= rhs.base();
	}

	template<typename Iterator, typename Container>
    bool	operator<=( const randomAccessIterator<Iterator, Container>& lhs,
	       const randomAccessIterator<Iterator, Container>& rhs )
    {
		return lhs.base() <= rhs.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	bool	operator>=( const randomAccessIterator<IteratorL, Container>& lhs,
	       const randomAccessIterator<IteratorR, Container>& rhs )
    {
		return lhs.base() >= rhs.base();
	}

	template<typename Iterator, typename Container>
    bool	operator>=( const randomAccessIterator<Iterator, Container>& lhs,
	       const randomAccessIterator<Iterator, Container>& rhs )
    {
		return lhs.base() >= rhs.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	typename randomAccessIterator<IteratorL, Container>::difference_type
    operator-( const randomAccessIterator<IteratorL, Container>& lhs,
	    const randomAccessIterator<IteratorR, Container>& rhs )
	{
		return lhs.base() - rhs.base();
	}

	template<typename Iterator, typename Container>
    typename randomAccessIterator<Iterator, Container>::difference_type
    operator-( const randomAccessIterator<Iterator, Container>& lhs,
	      const randomAccessIterator<Iterator, Container>& rhs )
    {
		return lhs.base() - rhs.base();
	}

	template<typename Iterator, typename Container>
    randomAccessIterator<Iterator, Container>
    operator+( typename randomAccessIterator<Iterator, Container>::difference_type n,
		const randomAccessIterator<Iterator, Container>& i )
    {
		return randomAccessIterator<Iterator, Container>(i.base() + n);
	}

} // namespace ft

#endif