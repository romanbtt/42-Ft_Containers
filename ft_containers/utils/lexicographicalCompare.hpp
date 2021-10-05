/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographicalCompare.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:55:43 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/29 16:51:14 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_H
#define LEXICOGRAPHICAL_COMPARE_H

namespace ft
{
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare ( InputIterator1 first1, InputIterator1 last1,
		InputIterator2 first2, InputIterator2 last2 )
	{
	  while (first1 != last1)
	  {
	    if (first2 == last2 || *first2 < *first1)
			return false;
	    else if (*first1 < *first2)
			return true;
	    ++first1;
		++first2;
	  }
	  return (first2 != last2);
	}

} // namespace ft

#endif