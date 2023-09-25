/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:24:44 by seunghye          #+#    #+#             */
/*   Updated: 2023/02/10 13:38:24 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <type_traits>

namespace ft {
	// enable_if
	template<bool Cond, typename T = void>
	struct enable_if {};

	template<typename T>
	struct enable_if<true, T>
	{ typedef T	type; };

	// remove_const
	template <typename T> struct  remove_const					{typedef T type;};
	template <typename T> struct  remove_const<const T>			{typedef T type;};
	// remove_volatile
	template <typename T> struct  remove_volatile				{typedef T type;};
	template <typename T> struct  remove_volatile<volatile T>	{typedef T type;};
	// remove_cv
	template <typename T> struct  remove_cv
	{typedef typename remove_volatile<typename remove_const<T>::type>::type type;};

	// integral_constant
	template <typename T, T v>
	struct integral_constant {
		static const T					value = v;
		typedef T						value_type;
		typedef integral_constant<T,v>	type;
		operator value_type() const { return v; }
		operator T() { return v; }
	};

	typedef	integral_constant<bool,true>	true_type;
	typedef	integral_constant<bool,false>	false_type;

	// is_integral
	template <typename T>
	struct ft_is_integral : public false_type {};
	template <> struct	ft_is_integral<bool>					: public true_type {};
	template <> struct	ft_is_integral<char>					: public true_type {};
	template <> struct	ft_is_integral<char16_t>				: public true_type {};
	template <> struct	ft_is_integral<char32_t>				: public true_type {};
	template <> struct	ft_is_integral<wchar_t>					: public true_type {};
	template <> struct	ft_is_integral<signed char>				: public true_type {};
	template <> struct	ft_is_integral<short int>				: public true_type {};
	template <> struct	ft_is_integral<int>						: public true_type {};
	template <> struct	ft_is_integral<long int>				: public true_type {};
	template <> struct	ft_is_integral<long long int>			: public true_type {};
	template <> struct	ft_is_integral<unsigned char>			: public true_type {};
	template <> struct	ft_is_integral<unsigned short int>		: public true_type {};
	template <> struct	ft_is_integral<unsigned int>			: public true_type {};
	template <> struct	ft_is_integral<unsigned long int>		: public true_type {};
	template <> struct	ft_is_integral<unsigned long long int>	: public true_type {};

	template <typename T>
	struct is_integral
	: public ft_is_integral<typename remove_cv<T>::type> {};
}



template <typename T>
T	add(T a, T b)
{
	return a+b;
}
