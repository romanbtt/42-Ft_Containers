/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:04:09 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/23 13:13:58 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
#define STACK_H

# include "vector.hpp"

namespace ft
{
	template <class T, class Sequence = ft::vector<T> >
	class stack
	{
	
	public:
    	typedef typename	Sequence::value_type		value_type;
    	typedef typename	Sequence::reference			reference;
    	typedef typename	Sequence::const_reference	const_reference;
    	typedef typename	Sequence::size_type			size_type;
    	typedef				Sequence					container_type;

		/*
		** Constructs a stack container adaptor object.
		*/

		explicit stack( const Sequence& c = Sequence() ) : c(c)
		{
			return ;
		}

		/*
		** Returns whether the stack is empty.
		*/

		bool empty( void ) const
		{
			return c.empty();
		}

		/*
		** Returns the number of elements in the stack.
		*/

		size_type size( void ) const
      	{
			return c.size();
		}

		/*
		** Returns a reference to the top element in the stack.
		*/

		reference top( void )
      	{
			return c.back();
      	}

		/*
		** Returns a const reference to the top element in the stack.
		*/

		const_reference top( void ) const
      	{
			return c.back();
      	}

		/*
		** Inserts a new element at the top of the stack,
		** above its current top element.
		** The content of this new element is initialized to a copy of val.
		*/

		void push( const value_type& val )
      	{
			c.push_back(val);
		}

		/*
		** Removes the element on top of the stack,
		** effectively reducing its size by one.
		*/

		void pop( void )
    	{	
			c.pop_back();
      	}

		/*
		** Allows the non member operator== to have access to the Sequence c.
		*/

		template<typename T1, typename Seq1>
		friend bool operator==(const stack<T1, Seq1>&, const stack<T1, Seq1>&);

		/*
		** Allows the non member operator< to have access to the Sequence c.
		*/

		template<typename T1, typename Seq1>
		friend bool operator<(const stack<T1, Seq1>&, const stack<T1, Seq1>&);

	protected:

		Sequence c;

	}; // class stack

		/*
		** Performs the appropriate comparison operation
		** between lhs (x) and rhs (y).
		*/

	template<typename T, typename Seq>
    bool operator==( const stack<T, Seq>& x, const stack<T, Seq>& y )
    {
		return x.c == y.c;
	}

	template<typename T, typename Seq>
    bool operator<( const stack<T, Seq>& x, const stack<T, Seq>& y )
    {
		return x.c < y.c;
	}

	template<typename T, typename Seq>
    bool
    operator!=( const stack<T, Seq>& x, const stack<T, Seq>& y )
    {
		return !(x == y);
	}

	template<typename T, typename Seq>
    bool operator>( const stack<T, Seq>& x, const stack<T, Seq>& y )
    {
		return y < x;
	}

	template<typename T, typename Seq>
    bool operator<=( const stack<T, Seq>& x, const stack<T, Seq>& y )
    {
		return !(y < x);
	}

	template<typename T, typename Seq>
    bool operator>=( const stack<T, Seq>& x, const stack<T, Seq>& y )
    {
		return !(x < y);
	}

} // namespace ft

#endif
