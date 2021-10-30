/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:01:47 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/23 20:55:48 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_H
# define PAIR_H

namespace ft
{
	template< typename T1, typename T2 >
	class pair
	{
		
	public:

		/*
		** Constructs a pair object with its elements value-initialized.
		*/

		pair( void ) : first(), second()
		{
			return ;
		}

		/*
		** Member first is constructed with a and member second with b.
		*/

		pair( const T1 & a, const T2  & b)
			: first(a), second(b)
		{
			return ;
		}

		/*
		** The object is initialized with the contents of the src pair object.
		** The corresponding member of pr is passed to the constructor of each
		** of its members.
		*/

		template< typename U1, typename U2 >
		pair(const pair< U1, U2 > & src)
			: first(src.first), second(src.second)
		{
			return ;
		}

		/*
		** Assigns rhs as the new content for the pair object.
		** Member first is assigned rhs.first,
		** and member second is assigned rhs.second.
		*/

		pair & operator=( const pair & rhs )
		{
			if (this != &rhs)
			{
				first = rhs.first;
				second = rhs.second;
			}
			return (*this);
		}

		T1 first;
		T2 second;
	};

	/*
	** Performs the appropriate comparison operation between
	** the pair objects lhs (x) and rhs (y).
	*/

	template < typename T1, typename T2 >
	bool operator==( const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y )
	{
		return (x.first == y.first && x.second == y.second);
	}

	template<typename T1, typename T2>
    bool	operator<( const pair<T1, T2>& x, const pair<T1, T2>& y )
    {
		return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
	}

	template<typename T1, typename T2>
	bool	operator!=( const pair<T1, T2>& x, const pair<T1, T2>& y)
    { 
		return !(x == y);
	}

	template<typename T1, typename T2>
    bool	operator>( const pair<T1, T2>& x, const pair<T1, T2>& y)
    {
		return y < x;
	}

	template<typename T1, typename T2>
    bool	operator<=( const pair<T1, T2>& x, const pair<T1, T2>& y)
    {
		return !(y < x);
	}

	template<typename T1, typename T2>
    bool	operator>=( const pair<T1, T2>& x, const pair<T1, T2>& y)
    {
		return !(x < y);
	}

	/*
	** Constructs a pair object with its first element
	** set to x and its second element set to y.
	*/
	
	template<typename T1, typename T2>
    pair<T1, T2>	make_pair(T1 x, T2 y)
    {
		return pair<T1, T2>(x, y);
	}

} // namespace ft

#endif
