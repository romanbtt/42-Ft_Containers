/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 22:23:42 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/24 00:11:39 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef reverse_iterator_H
# define reverse_iterator_H

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

		/*
		** Constructs a reverse iterator that points to no object.
		*/
	
		reverse_iterator( void ) : _current()
		{
			return ;
		};

		/*
		** Constructs a reverse iterator from some original iterator it.
		** The behavior of the constructed object replicates the original,
		** except that it iterates through its pointed elements
		** in the reverse order.
		*/

		explicit reverse_iterator( iterator_type it ) : _current(it)
		{
			return ;
		}

		/*
		** Constructs a reverse iterator from some other reverse iterator.
		*/

		reverse_iterator( const reverse_iterator & it )
			: _current(it._current)
		{
			return ;
		}

		/*
        **  A reverse_iterator from other types can be copied if the
        **  underlying iterator can be converted to the type of _current.
      	*/

		template<typename Iter>
		reverse_iterator( const reverse_iterator<Iter> & it )
			: _current(it.base())
		{
			return ;
		}

		/*
		** Returns a copy of _current
		*/

		iterator_type base( void ) const
		{
			return _current;
		}

		/*
		** Returns a reference to the element pointed to by the iterator.
		** Tthe function decreases a copy of its base iterator and
		** returns the result of dereferencing it.
		*/

		reference	operator*( void ) const
		{
			Iterator tmp = _current;
			return *--tmp;
		}

		/*
		** Returns a pointer to the element pointed to by the iterator
		** (in order to access one of its members).
		*/

		pointer	operator->( void ) const
		{
			return &(operator*());
		}

		/*
		** Pre increment version
		** Advances the reverse_iterator by one position.
		*/

		reverse_iterator & operator++( void )
		{
			--_current;
			return *this;
		}

		/*
		** Post increment version
		** Advances the reverse_iterator by one position.
		*/

		reverse_iterator	operator++( int )
		{
			reverse_iterator tmp = *this;
			
			--_current;
			return tmp;
		}

		/*
		** Pre decrement version
		** Decreases the reverse_iterator by one position.
		*/

		reverse_iterator & operator--( void )
		{
			++_current;
			return *this;
		}

		/*
		** Post decrement version
		** Decreases the reverse_iterator by one position.
		*/

		reverse_iterator	operator--( int )
		{
			reverse_iterator tmp = *this;
			
			++_current;
			return tmp;
		}

		/*
		** Returns a reverse iterator pointing to the element located
		** n positions away from the element the iterator currently points to.
		** Internally, the function applies the binary operator- on the base
		** iterator and returns a reverse iterator constructed with
		** the resulting iterator value.
		*/

		reverse_iterator	operator+( difference_type n ) const
		{
			return reverse_iterator(_current - n);
		}

		/*
		** Advances the reverse_iterator by n element positions.
		** Internally, the function decreases by n the base iterator
		** kept by the object (as if applying operator-= to it).
		*/

		reverse_iterator &	operator+=( difference_type n )
		{
			_current -= n;
			return *this;
		}

		/*
		** Returns a reverse iterator pointing to the element located 
		** n positions before the element the iterator currently points to.
		** Internally, the function applies the binary operator+ on
		** the base iterator and returns a reverse iterator constructed with
		** the resulting iterator value.
		*/

		reverse_iterator	operator-( difference_type n ) const
		{
			return reverse_iterator(_current + n);
		}

		/*
		** Descreases the reverse_iterator by n element positions.
		** Internally, the function increases by n the base iterator kept by
		** the object (as if applying operator+= to it).
		*/

		reverse_iterator &	operator-=( difference_type n )
		{
			_current += n;
			return *this;
		}

		/*
		** Accesses the element located n positions away from the element
		** currently pointed to by the iterator.
		** If such an element does not exist, it causes undefined behavior.
		*/

		reference	operator[]( difference_type n ) const
		{
			return *(*this + n);
		}

	}; // class reverse_iterator

	/*
	** Performs the appropriate comparison operation between the
	** reverse_iterator objects lhs (x) and rhs (y).
	*/

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

	/*
	** Returns the distance between lhs (x) and rhs (y).
	*/

	template<typename Iterator>
    typename reverse_iterator<Iterator>::difference_type
    operator-( const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y )
    {
		return y.base() - x.base();
	}

	/*
	** operator- must accept mixed iterator/const_iterator parameters.
	*/

	template<typename IteratorL, typename IteratorR>
    typename reverse_iterator<IteratorL>::difference_type
    operator-( const reverse_iterator<IteratorL>& x,
		const reverse_iterator<IteratorR>& y )
    {
		return y.base() - x.base();
	}

	/*
	** Returns a reverse iterator pointing to the element located n
	** positions away from the element pointed to by x.
	*/

	template<typename Iterator>
    reverse_iterator<Iterator>
    operator+( typename reverse_iterator<Iterator>::difference_type n,
	    const reverse_iterator<Iterator>& x )
    {
		return reverse_iterator<Iterator>(x.base() - n);
	}

} // namespace ft

#endif
