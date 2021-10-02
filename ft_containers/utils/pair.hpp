/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:01:47 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/02 11:55:53 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_H
#define PAIR_H

namespace ft
{
	template< typename T1, typename T2 >
	struct pair
	{
		
		typedef T1 first_type;
		typedef T2 second_type;

		T1 first;
		T2 second;

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
		pair(const pair<U1, U2>& p)
			: first(p.first), second(p.second)
		{
			return ;
		}

		template <class T1, class T2>
		bool operator==(const ft::pair<T1,T2> & x, const ft::pair<T1,T2> & y)
		{
			return (x.first == y.first && x.second == y.second);
		}

		  template<typename _T1, typename _T2>
    inline _GLIBCXX_CONSTEXPR bool
    operator<(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
    { return __x.first < __y.first
	     || (!(__y.first < __x.first) && __x.second < __y.second); }


	}
} // namespace ft

#endif