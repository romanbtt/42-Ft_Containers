/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:50:12 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/20 21:33:26 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LESS_H
#define LESS_H

#include <functional>

namespace ft
{
	template <class T>
	struct less : std::binary_function <T, T, bool>
	{
		bool operator()(const T& x, const T& y) const
	  	{
			return x < y;
		}
	};
	
} // namespace ft

#endif
