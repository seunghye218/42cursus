/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:32:48 by seunghye          #+#    #+#             */
/*   Updated: 2023/02/02 19:29:10 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// #include <stack>

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = vector<T> >
	class stack
	{
	protected:
		Container c;
	public:
		typedef typename Container::value_type	value_type;
		typedef typename Container::size_type 	size_type;
		typedef Container						container_type;

		stack() : c() {}
		explicit stack(const Container& seq) : c(seq) {}
		bool empty() const
		{ return c.empty(); }
		size_type size() const
		{ return c.size(); }
		value_type& top()
		{ return c.back(); }
		const value_type& top() const
		{ return c.back(); }
		void push(const value_type& x)
		{ c.push_back(x); }
		void pop()
		{ c.pop_back(); }

		template<typename T1, typename Container1>
		friend bool	operator==(const stack<T1, Container1>&, const stack<T1, Container1>&);
		template<typename T1, typename Container1>
		friend bool	operator<(const stack<T1, Container1>&, const stack<T1, Container1>&);
	};

	template <class T, class Container>
	inline bool	operator==(const stack<T, Container>& x, const stack<T, Container>& y)
	{ return x.c == y.c; }
	template <class T, class Container>
	inline bool	operator< (const stack<T, Container>& x, const stack<T, Container>& y)
	{ return x.c < y.c; }
	template <class T, class Container>
	inline bool	operator!=(const stack<T, Container>& x, const stack<T, Container>& y)
	{ return !(x == y); }
	template <class T, class Container>
	inline bool	operator> (const stack<T, Container>& x, const stack<T, Container>& y)
	{ return y < x; }
	template <class T, class Container>
	inline bool	operator>=(const stack<T, Container>& x, const stack<T, Container>& y)
	{ return !(x < y); }
	template <class T, class Container>
	inline bool	operator<=(const stack<T, Container>& x, const stack<T, Container>& y)
	{ return !(y < x); }
}
