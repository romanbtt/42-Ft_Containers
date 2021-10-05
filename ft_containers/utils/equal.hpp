/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:55:23 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/02 14:01:33 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_H
#define EQUAL_H

namespace ft
{
	template<class IIter1, class IIter2>
	bool
	equal(IIter1 first1, IIter1 last1, IIter2 first2)
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

	// Predicate
	template<class IIter1, class IIter2, class BinaryPredicate>
	bool	equal(IIter1 first1, IIter1 last1, IIter2 first2, BinaryPredicate p)
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
}

#endif