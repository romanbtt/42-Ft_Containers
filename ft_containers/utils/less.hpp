/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:50:12 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/29 16:53:32 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LESS_H
#define LESS_H

namespace ft
{
	template <class T>
	struct less : binary_function <T, T, bool>
	{
	  bool operator()(const T& x, const T& y) const
	  {
		  return x<y;
		}
	};
} // namespace ft

#endif