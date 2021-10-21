/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:04:09 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/20 21:33:55 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

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

		explicit stack( const Sequence& c = Sequence() ) : _c(c)
		{
			return ;
		}

		bool empty( void ) const
		{
			return _c.empty();
		}

		size_type size( void ) const
      	{
			return _c.size();
		}

		reference top( void )
      	{
			return _c.back();
      	}

		const_reference top( void ) const
      	{
			return _c.back();
      	}

		void push( const value_type& x )
      	{
			_c.push_back(x);
		}

		void pop( void )
    	{	
			_c.pop_back();
      	}

		template<typename T1, typename Seq1>
		friend bool operator==(const stack<T1, Seq1>&, const stack<T1, Seq1>&);

		template<typename T1, typename Seq1>
		friend bool operator<(const stack<T1, Seq1>&, const stack<T1, Seq1>&);

	protected:

		Sequence _c;
	};

	template<typename T, typename Seq>
    bool operator==( const stack<T, Seq>& x, const stack<T, Seq>& y )
    {
		return x._c == y._c;
	}

	template<typename T, typename Seq>
    bool operator<( const stack<T, Seq>& x, const stack<T, Seq>& y )
    {
		return x._c < y._c;
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
