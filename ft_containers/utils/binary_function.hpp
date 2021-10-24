/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_function.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:05:54 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/23 21:14:18 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_FUNCTION_H
# define BINARY_FUNCTION_H

namespace ft
{

  /*
  ** Base class for standard binary function objects.
  */

	template<typename Arg1, typename Arg2, typename Result>
    struct binary_function
    {
      typedef Arg1		first_argument_type; 
      typedef Arg2		second_argument_type;
      typedef Result 	result_type;
      
    }; // struct binary_function

} // namespace ft

#endif
