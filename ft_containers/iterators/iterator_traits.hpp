/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:04:26 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/07 17:40:24 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_H
#define ITERATOR_TRAITS_H

# include <bits/c++config.h>

namespace ft
{
	struct input_iterator_tag {};

	struct output_iterator_tag {};

	struct forward_iterator_tag: public input_iterator_tag {};

	struct bidirectional_iterator_tag: public forward_iterator_tag {};

	struct random_access_iterator_tag: public bidirectional_iterator_tag {};

	template<typename Category, typename T, typename Distance = std::ptrdiff_t,
		typename Pointer = T*, typename Reference = T&>
	struct iterator
	{
		typedef Category 									iterator_category;
		typedef T											value_type;
		typedef Distance 									difference_type;
		typedef Pointer										pointer;
		typedef Reference 									reference;
	};

  template<typename Iterator>
    struct iterator_traits
    {
      typedef typename Iterator::iterator_category 			iterator_category;
      typedef typename Iterator::value_type        			value_type;
      typedef typename Iterator::difference_type   			difference_type;
      typedef typename Iterator::pointer					pointer;
      typedef typename Iterator::reference        			reference;
    };

	template<typename T>
	struct iterator_traits<T*>
	{
		typedef random_access_iterator_tag					iterator_category;
		typedef T											value_type;
		typedef std::ptrdiff_t								difference_type;
		typedef T*											pointer;
		typedef T&											reference;
		
	};

	template<typename T>
	struct iterator_traits<const T*>
	{
		typedef random_access_iterator_tag					iterator_category;
		typedef T											value_type;
		typedef std::ptrdiff_t								difference_type;
		typedef const T*									pointer;
		typedef const T&									reference;
		
	};
	
} // namespace ft

#endif
