/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:01:47 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/20 21:33:20 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_H
#define PAIR_H

namespace ft
{
	template< typename T1, typename T2 >
	class pair
	{
		
	public:

		pair( void ) : first(), second()
		{
			return ;
		}

		pair( const T1 & a, const T2  & b)
			: first(a), second(b)
		{
			return ;
		}

		template< typename U1, typename U2 >
		pair(const pair< U1, U2 > & src)
			: first(src.first), second(src.second)
		{
			return ;
		}

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
	
	template<typename T1, typename T2>
    pair<T1, T2>	make_pair(T1 x, T2 y)
    {
		return pair<T1, T2>(x, y);
	}

} // namespace ft

#endif
