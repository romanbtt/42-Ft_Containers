/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:04:23 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/24 00:15:51 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_iTERATOR_H
# define RANDOM_ACCESS_iTERATOR_H

# include "iterator_traits.hpp"
# include "type_traits.hpp"

namespace ft
{

	template<typename Iterator, typename Container>
	class random_access_iterator
	{
	protected:

		Iterator _current;
		typedef iterator_traits<Iterator>				traits_type;

	public:
			
		typedef Iterator								iterator_type;
		typedef typename traits_type::iterator_category	iterator_category;
		typedef typename traits_type::value_type 		value_type;
		typedef typename traits_type::difference_type 	difference_type;
		typedef typename traits_type::reference 		reference;
		typedef typename traits_type::pointer 			pointer;

		/*
		** Constructs a random_access iterator with the
		** default value of iterator. (pointer)
		*/

		random_access_iterator() : _current(Iterator())
		{
			return ;
		}

		/*
		** Constructs a random_access iterator that points to it.
		*/

		explicit random_access_iterator( const Iterator& it ) : _current(it)
		{
			return ;
		}

		/*
		** Allow a iterator to const_iterator conversion
		*/
		
		template<typename Iter>
		random_access_iterator( const random_access_iterator<Iter, typename ft::enable_if<
		(ft::is_same<Iter, typename Container::pointer>::value),
		Container>::type>& it) : _current(it.base() )
		{
			return ;
		}

		/*
		** Destructor
		*/

		~random_access_iterator( void )
		{
			return ;
		}

		/*
		** Returns a reference to the element pointed to by the iterator.
		*/

		reference	operator*( void ) const
		{
				return *_current;
		}

		/*
		** Returns a pointer to the element pointed to by the iterator.
		*/

		pointer	operator->( void ) const
		{
				return _current;
		}

		/*
		** Pre increment version
		** Advances the random_access_iterator by one position.
		*/

		random_access_iterator& operator++( void )
		{
			++_current;
			return *this;
		}

		/*
		** Post increment version
		** Advances the random_access_iterator by one position.
		*/

		random_access_iterator	operator++( int ) 
		{
			return random_access_iterator(_current++);
		}

		/*
		** Pre decrement version
		** Decreases the random_access_iterator by one position.
		*/

		random_access_iterator&	operator--( void )
		{
			--_current;
			return *this;
		}

		/*
		** Post decrement version
		** Decreases the random_access_iterator by one position.
		*/

		random_access_iterator	operator--( int )
		{
			return random_access_iterator(_current--);
		}

		/*
		** Accesses the element located n positions away from the element
		** currently pointed to by the iterator.
		** If such an element does not exist, it causes undefined behavior.
		*/

		reference	operator[]( difference_type n ) const
		{
			return _current[n];
		}

		/*
		** Advances the random_access_iterator by n element positions.
		*/

		random_access_iterator & operator+=( difference_type n )
		{
			_current += n;
			return *this;
		}

		/*
		** Returns a random_access_iterator pointing to the element located
		** n positions away from the element the iterator currently points to.
		*/

		random_access_iterator	operator+( difference_type n ) const
		{
			return random_access_iterator(_current + n);
		}

		/*
		** Descreases the reverse_iterator by n element positions.
		*/

		random_access_iterator&	operator-=( difference_type n )
		{
			_current -= n;
			return *this;
		}

		/*
		** Returns a reverse iterator pointing to the element located 
		** n positions before the element the iterator currently points to.
		*/

		random_access_iterator	operator-( difference_type n ) const
		{
			return random_access_iterator(_current - n);
		}

		/*
		** Returns a copy of _current
		*/

		const Iterator&	base( void ) const
		{
			return _current;
		}
	};

	/*
	** Performs the appropriate comparison operation between the
	** reverse_iterator objects x (x) and y (y).
	*/

	template<typename IteratorL, typename IteratorR, typename Container>
    bool	operator==( const random_access_iterator<IteratorL, Container>& x,
	       const random_access_iterator<IteratorR, Container>& y )
    {
		return x.base() == y.base();
	}

	template<typename Iterator, typename Container>
    bool	operator==( const random_access_iterator<Iterator, Container>& x,
	       const random_access_iterator<Iterator, Container>& y )
    {
		return x.base() == y.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	bool	operator!=( const random_access_iterator<IteratorL, Container>& x,
	       const random_access_iterator<IteratorR, Container>& y )
    {
		return x.base() != y.base();
	}

	template<typename Iterator, typename Container>
    bool	operator!=( const random_access_iterator<Iterator, Container>& x,
	       const random_access_iterator<Iterator, Container>& y )
    {
		return x.base() != y.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	bool	operator<( const random_access_iterator<IteratorL, Container>& x,
	       const random_access_iterator<IteratorR, Container>& y )
    {
		return x.base() < y.base();
	}

	template<typename Iterator, typename Container>
    bool	operator<( const random_access_iterator<Iterator, Container>& x,
	       const random_access_iterator<Iterator, Container>& y )
    {
		return x.base() < y.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	bool	operator>( const random_access_iterator<IteratorL, Container>& x,
	       const random_access_iterator<IteratorR, Container>& y )
    {
		return x.base() > y.base();
	}

	template<typename Iterator, typename Container>
    bool	operator>( const random_access_iterator<Iterator, Container>& x,
	       const random_access_iterator<Iterator, Container>& y )
    {
		return x.base() > y.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	bool	operator<=( const random_access_iterator<IteratorL, Container>& x,
	       const random_access_iterator<IteratorR, Container>& y )
    {
		return x.base() <= y.base();
	}

	template<typename Iterator, typename Container>
    bool	operator<=( const random_access_iterator<Iterator, Container>& x,
	       const random_access_iterator<Iterator, Container>& y )
    {
		return x.base() <= y.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	bool	operator>=( const random_access_iterator<IteratorL, Container>& x,
	       const random_access_iterator<IteratorR, Container>& y )
    {
		return x.base() >= y.base();
	}

	template<typename Iterator, typename Container>
    bool	operator>=( const random_access_iterator<Iterator, Container>& x,
	       const random_access_iterator<Iterator, Container>& y )
    {
		return x.base() >= y.base();
	}

	/*
	** operator- must accept mixed iterator/const_iterator parameters.
	*/

	template<typename IteratorL, typename IteratorR, typename Container>
	typename random_access_iterator<IteratorL, Container>::difference_type
    operator-( const random_access_iterator<IteratorL, Container>& x,
	    const random_access_iterator<IteratorR, Container>& y )
	{
		return x.base() - y.base();
	}

	/*
	** Returns the distance between lhs (x) and rhs (y).
	*/

	template<typename Iterator, typename Container>
    typename random_access_iterator<Iterator, Container>::difference_type
    operator-( const random_access_iterator<Iterator, Container>& x,
	      const random_access_iterator<Iterator, Container>& y )
    {
		return x.base() - y.base();
	}

	/*
	** Returns a random_access_iterator pointing to the element located n
	** positions away from the element pointed to by x.
	*/

	template<typename Iterator, typename Container>
    random_access_iterator<Iterator, Container>
    operator+( typename random_access_iterator<Iterator, Container>::difference_type n,
		const random_access_iterator<Iterator, Container>& i )
    {
		return random_access_iterator<Iterator, Container>(i.base() + n);
	}

} // namespace ft

#endif
