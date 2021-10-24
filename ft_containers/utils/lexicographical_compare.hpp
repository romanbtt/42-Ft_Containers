/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:55:43 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/23 22:23:14 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_H
# define LEXICOGRAPHICAL_COMPARE_H

namespace ft
{

	/*
	** Returns true if the range [first1,last1)
	** compares lexicographically less than the range [first2,last2).
	*/

	template <typename input_iterator_1, typename input_iterator_2>
	bool lexicographical_compare( input_iterator_1 first1, input_iterator_1 last1,
		input_iterator_2 first2, input_iterator_2 last2 )
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

	/*
	** Compares lexicographically [first1,last1) and [first2,last2) using
	** the comp function.
	*/

	template <typename input_iterator_1, typename input_iterator_2, typename Compare>
	bool lexicographical_compare( input_iterator_1 first1, input_iterator_1 last1,
		input_iterator_2 first2, input_iterator_2 last2, Compare comp)
	{
		 while (first1 != last1)
	  	{
	    	if (first2 == last2 || comp(*first2, *first1))
				return false;
	    	else if (comp(*first1, *first2))
				return true;
	    	++first1;
			++first2;
		}
		return (first2 != last2);
	}

} // namespace ft

#endif
