/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:42:50 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/23 21:08:46 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISTANCE_H
# define DISTANCE_H

# include "../iterators/iterator_traits.hpp"

namespace ft
{

    /*
    ** Determine the category of iterator.
    */

    template<typename Iter>
    typename iterator_traits<Iter>::iterator_category
    iterator_category(const Iter &)
    {
        return typename ft::iterator_traits<Iter>::iterator_category();
    }

    /*
    ** Specialization using operator++ repeatedly to calculate the distance
    ** between first and last.
    */

    template < typename input_iterator >
    typename ft::iterator_traits<input_iterator>::difference_type
    distance( input_iterator first, input_iterator last, ft::input_iterator_tag )
    {
        typename ft::iterator_traits<input_iterator>::difference_type n = 0;

        while (first != last)
    	{
    	    ++first;
    	    ++n;
    	}   
        return n;
    }

    /*
    ** Specialization using operator- to calculate the distance
    ** between first and last.
    */

    template < typename random_access_iterator >
    typename ft::iterator_traits<random_access_iterator>::difference_type
    distance( random_access_iterator first, random_access_iterator last,
        ft::random_access_iterator_tag )
    {
        return last - first;
    }

    /*
    ** Calculates the number of elements between first and last.
    ** If it is a random-access iterator, the function uses operator-
    ** to calculate this.
    ** Otherwise, the function uses the increase operator (operator++)
    ** repeatedly.
    */

    template< typename input_iterator >
    typename ft::iterator_traits<input_iterator>::difference_type
    distance(input_iterator first, input_iterator last)
    {
        return distance(first, last, ft::iterator_category(first));
    }

} // namespace ft

#endif
