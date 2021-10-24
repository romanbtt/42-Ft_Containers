/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:50:12 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/23 21:02:30 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LESS_H
# define LESS_H

# include <functional>

namespace ft
{

	/*
	** Binary function object class whose call returns whether
	** the its first argument compares less than the second
	** (as returned by operator <).
	*/

	template <typename T>
	struct less : std::binary_function <T, T, bool>
	{
		bool operator()(const T& x, const T& y) const
	  	{
			return x < y;
		}
	}; // struct less
	
} // namespace ft

#endif
