/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeTraits.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:08:40 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/02 14:24:29 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPETRAITS_H
#define TYPETRAITS_H

#include <bits/c++config.h>

namespace ft
{

	template<bool, typename T = void>
	struct enableIf
	{ };

	template<typename T>
	struct enableIf<true, T>
	{
		typedef T type;
	};

	template<typename T, T v>
	struct integralConstant
	{
	    static const T                		value = v;
	    typedef T							valueType;
	    typedef integralConstant<T, v>   	type;

	    operator valueType() const
		{
			return value;
		}
	};

	typedef integralConstant<bool, true>	trueType;

	typedef integralConstant<bool, false>	falseType;

	template<typename>
	struct isIntegralHelper : public falseType { };

	template<>
	struct isIntegralHelper<bool> : public trueType { };

	template<>
	struct isIntegralHelper<char> : public trueType { };

	template<>
	struct isIntegralHelper<signed char> : public trueType { };

	template<>
	struct isIntegralHelper<unsigned char> : public trueType { };

	#ifdef _GLIBCXX_USE_WCHAR_T
	template<>
	struct isIntegralHelper<wchar_t> : public trueType { };
	#endif

	#ifdef _GLIBCXX_USE_CHAR8_T
	template<>
	struct isIntegralHelper<char8_t> : public trueType { };
	#endif

	template<>
	struct isIntegralHelper<short> : public trueType { };

	template<>
	struct isIntegralHelper<unsigned short> : public trueType { };

	template<>
	struct isIntegralHelper<int> : public trueType { };

	template<>
	struct isIntegralHelper<unsigned int> : public trueType { };

	template<>
	struct isIntegralHelper<long> : public trueType { };

	template<>
	struct isIntegralHelper<unsigned long> : public trueType { };

	template<typename T>
	struct isIntegral : public isIntegralHelper<T> { };

	template<typename, typename>
    struct isSame : public falseType { };

  	template<typename T>
    struct isSame<T, T> : public trueType { };

} // namespace ft

#endif