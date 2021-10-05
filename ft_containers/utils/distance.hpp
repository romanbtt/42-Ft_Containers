/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:42:50 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/02 16:38:58 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISTANCE_H
#define DISTANCE_H

#include "../iterators/iteratorTraits.hpp"

namespace ft
{

    template<typename Iter>
    typename iteratorTraits<Iter>::iterator_category
    iteratorCategory(const Iter &)
    {
        return typename ft::iteratorTraits<Iter>::iterator_category();
    }

    template < typename InputIterator >
    typename ft::iteratorTraits<InputIterator>::difference_type
    distance( InputIterator first, InputIterator last, ft::input_iterator_tag )
    {
        typename ft::iteratorTraits<InputIterator>::difference_type n = 0;

        while (first != last)
    	{
    	    ++first;
    	    ++n;
    	}   
        return n;
    }

    template < typename RandomAccessIterator >
    typename ft::iteratorTraits<RandomAccessIterator>::difference_type
    distance( RandomAccessIterator first, RandomAccessIterator last,
        ft::random_access_iterator_tag )
    {
        return last - first;
    }

    template< typename InputIterator >
    typename ft::iteratorTraits<InputIterator>::difference_type
    distance(InputIterator first, InputIterator last)
    {
        return distance(first, last, ft::iteratorCategory(first));
    }

    } // namespace ft

#endif