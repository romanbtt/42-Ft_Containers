/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:55:23 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/23 00:14:37 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_H
#define EQUAL_H

namespace ft
{
	template<class input_iterator_1, class input_iterator_2>
	bool	equal( input_iterator_1 first1, input_iterator_1 last1,
		input_iterator_2 first2 )
	{
		while (first1 != last1)
		{
			if (*first1 != *first2)
				return false;
			first1++;
			first2++;
		}

		return true;
	}

	template<class input_iterator_1, class input_iterator_2, class binary_predicate>
	bool	equal( input_iterator_1 first1, input_iterator_1 last1,
		input_iterator_2 first2, binary_predicate p )
	{
		while (first1 != last1)
		{
			if (!p(*first1, *first2))
				return false;
			first1++;
			first2++;
		}
		return true;
	}
} // namespace ft

#endif
