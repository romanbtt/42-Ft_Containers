/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_function.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:05:54 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/20 21:33:35 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_FUNCTION_H
#define BINARY_FUNCTION_H

namespace ft
{
	template<typename Arg1, typename Arg2, typename Result>
    struct binary_function
    {
      typedef Arg1		first_argument_type; 
      typedef Arg2		second_argument_type;
      typedef Result 	result_type;
    };	

} // namespace ft

#endif
