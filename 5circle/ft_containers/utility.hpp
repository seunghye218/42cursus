/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:05:28 by seunghye          #+#    #+#             */
/*   Updated: 2023/01/26 16:47:01 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <utility>
#include <string>

#include "type_traits.hpp"
#include "algorithm.hpp"
#include "iterator.hpp"

namespace ft {
	// pair
	template <typename T1, typename T2>
	struct	pair {
		typedef T1	first_type;
		typedef T2	second_type;
		T1	first;
		T2	second;
		pair() : first(T1()), second(T2()) {}
		pair(const T1& x, const T2& y) : first(x), second(y) {}
		template<typename U, typename V> 
		pair(const pair<U, V> &p) : first(p.first), second(p.second) {}
	};

	template <typename T1, typename T2>
	bool	operator==(const pair<T1,T2>& x, const pair<T1,T2>& y)
	{ return x.first == y.first && x.second == y.second; }
	template <typename T1, typename T2>
	bool	operator!=(const pair<T1,T2>& x, const pair<T1,T2>& y)
	{ return !(x == y); }
	template <typename T1, typename T2>
	bool	operator< (const pair<T1,T2>& x, const pair<T1,T2>& y)
	{ return x.first < y.first || (!(y.first < x.first) && x.second < y.second); }
	template <typename T1, typename T2>
	bool	operator> (const pair<T1,T2>& x, const pair<T1,T2>& y)
	{ return y < x; }
	template <typename T1, typename T2>
	bool	operator>=(const pair<T1,T2>& x, const pair<T1,T2>& y)
	{ return !(x < y); }
	template <typename T1, typename T2>
	bool	operator<=(const pair<T1,T2>& x, const pair<T1,T2>& y)
	{ return !(y < x); }

	template <typename T1, typename T2>
	pair<T1,T2>	make_pair(T1 x, T2 y)
	{ return pair<T1, T2>(x, y); }

}
