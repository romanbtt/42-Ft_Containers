/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:04:23 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/20 21:00:43 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_iTERATOR_H
#define RANDOM_ACCESS_iTERATOR_H

# include "iterator_traits.hpp"
# include "type_traits.hpp"

namespace ft
{

	template<typename Iterator, typename Container>
	class random_access_iterator
	{
		protected:

			Iterator _current;
			typedef iterator_traits<Iterator>				traitsType;

		public:
			
			typedef Iterator								iterator_type;
			typedef typename traitsType::iterator_category	iterator_category;
			typedef typename traitsType::value_type 		value_type;
			typedef typename traitsType::difference_type 	difference_type;
			typedef typename traitsType::reference 			reference;
			typedef typename traitsType::pointer 			pointer;

			random_access_iterator() : _current(Iterator())
			{
				return ;
			}

			explicit random_access_iterator( const Iterator & it ) : _current(it)
			{
				return ;
			}
			
      		template<typename Iter>
    		random_access_iterator( const random_access_iterator<Iter, typename ft::enable_if<
      	    (ft::is_same<Iter, typename Container::pointer>::value),
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

			random_access_iterator & operator++( void )
      		{
				++_current;
				return *this;
      		}

			random_access_iterator	operator++( int ) 
      		{
				return random_access_iterator(_current++);
			}

			random_access_iterator &	operator--( void )
      		{
				--_current;
				return *this;
      		}

			random_access_iterator	operator--( int )
      		{
				return random_access_iterator(_current--);
			}

			reference	operator[]( difference_type n ) const
      		{
				return _current[n];
			}

			random_access_iterator & operator+=( difference_type n )
      		{
				_current += n;
				return *this;
			}

			random_access_iterator	operator+( difference_type n ) const
      		{
				return random_access_iterator(_current + n);
			}

			random_access_iterator &	operator-=( difference_type n )
      		{
				_current -= n;
				return *this;
			}

			random_access_iterator	operator-( difference_type n ) const
      		{
				return random_access_iterator(_current - n);
			}

			const Iterator &	base( void ) const
      		{
				return _current;
			}
	};

	template<typename IteratorL, typename IteratorR, typename Container>
    bool	operator==( const random_access_iterator<IteratorL, Container>& lhs,
	       const random_access_iterator<IteratorR, Container>& rhs )
    {
		return lhs.base() == rhs.base();
	}

	template<typename Iterator, typename Container>
    bool	operator==( const random_access_iterator<Iterator, Container>& lhs,
	       const random_access_iterator<Iterator, Container>& rhs )
    {
		return lhs.base() == rhs.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	bool	operator!=( const random_access_iterator<IteratorL, Container>& lhs,
	       const random_access_iterator<IteratorR, Container>& rhs )
    {
		return lhs.base() != rhs.base();
	}

	template<typename Iterator, typename Container>
    bool	operator!=( const random_access_iterator<Iterator, Container>& lhs,
	       const random_access_iterator<Iterator, Container>& rhs )
    {
		return lhs.base() != rhs.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	bool	operator<( const random_access_iterator<IteratorL, Container>& lhs,
	       const random_access_iterator<IteratorR, Container>& rhs )
    {
		return lhs.base() < rhs.base();
	}

	template<typename Iterator, typename Container>
    bool	operator<( const random_access_iterator<Iterator, Container>& lhs,
	       const random_access_iterator<Iterator, Container>& rhs )
    {
		return lhs.base() < rhs.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	bool	operator>( const random_access_iterator<IteratorL, Container>& lhs,
	       const random_access_iterator<IteratorR, Container>& rhs )
    {
		return lhs.base() > rhs.base();
	}

	template<typename Iterator, typename Container>
    bool	operator>( const random_access_iterator<Iterator, Container>& lhs,
	       const random_access_iterator<Iterator, Container>& rhs )
    {
		return lhs.base() > rhs.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	bool	operator<=( const random_access_iterator<IteratorL, Container>& lhs,
	       const random_access_iterator<IteratorR, Container>& rhs )
    {
		return lhs.base() <= rhs.base();
	}

	template<typename Iterator, typename Container>
    bool	operator<=( const random_access_iterator<Iterator, Container>& lhs,
	       const random_access_iterator<Iterator, Container>& rhs )
    {
		return lhs.base() <= rhs.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	bool	operator>=( const random_access_iterator<IteratorL, Container>& lhs,
	       const random_access_iterator<IteratorR, Container>& rhs )
    {
		return lhs.base() >= rhs.base();
	}

	template<typename Iterator, typename Container>
    bool	operator>=( const random_access_iterator<Iterator, Container>& lhs,
	       const random_access_iterator<Iterator, Container>& rhs )
    {
		return lhs.base() >= rhs.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	typename random_access_iterator<IteratorL, Container>::difference_type
    operator-( const random_access_iterator<IteratorL, Container>& lhs,
	    const random_access_iterator<IteratorR, Container>& rhs )
	{
		return lhs.base() - rhs.base();
	}

	template<typename Iterator, typename Container>
    typename random_access_iterator<Iterator, Container>::difference_type
    operator-( const random_access_iterator<Iterator, Container>& lhs,
	      const random_access_iterator<Iterator, Container>& rhs )
    {
		return lhs.base() - rhs.base();
	}

	template<typename Iterator, typename Container>
    random_access_iterator<Iterator, Container>
    operator+( typename random_access_iterator<Iterator, Container>::difference_type n,
		const random_access_iterator<Iterator, Container>& i )
    {
		return random_access_iterator<Iterator, Container>(i.base() + n);
	}

} // namespace ft

#endif
