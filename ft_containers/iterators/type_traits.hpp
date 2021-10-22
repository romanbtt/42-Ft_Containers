/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:08:40 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/20 21:33:37 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPETRAITS_H
#define TYPETRAITS_H

#include <bits/c++config.h>

namespace ft
{

	template<bool, typename T = void>
	struct enable_if
	{ };

	template<typename T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	template<typename T, T v>
	struct integral_constant
	{
	    static const T                		value = v;
	    typedef T							value_type;
	    typedef integral_constant<T, v>   	type;

	    operator value_type() const
		{
			return value;
		}
	};

	typedef integral_constant<bool, true>	true_type;

	typedef integral_constant<bool, false>	false_type;

	template<typename>
	struct is_integral_helper : public false_type { };

	template<>
	struct is_integral_helper<bool> : public true_type { };

	template<>
	struct is_integral_helper<char> : public true_type { };

	template<>
	struct is_integral_helper<signed char> : public true_type { };

	template<>
	struct is_integral_helper<unsigned char> : public true_type { };

	#ifdef _GLIBCXX_USE_WCHAR_T
	template<>
	struct is_integral_helper<wchar_t> : public true_type { };
	#endif

	#ifdef _GLIBCXX_USE_CHAR8_T
	template<>
	struct is_integral_helper<char8_t> : public true_type { };
	#endif

	template<>
	struct is_integral_helper<short> : public true_type { };

	template<>
	struct is_integral_helper<unsigned short> : public true_type { };

	template<>
	struct is_integral_helper<int> : public true_type { };

	template<>
	struct is_integral_helper<unsigned int> : public true_type { };

	template<>
	struct is_integral_helper<long> : public true_type { };

	template<>
	struct is_integral_helper<unsigned long> : public true_type { };

	template<typename T>
	struct isIntegral : public is_integral_helper<T> { };

	template<typename, typename>
    struct is_same : public false_type { };

  	template<typename T>
    struct is_same<T, T> : public true_type { };

} // namespace ft

#endif