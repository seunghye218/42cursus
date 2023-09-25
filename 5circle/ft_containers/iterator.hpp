/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:14:23 by seunghye          #+#    #+#             */
/*   Updated: 2023/02/07 16:07:32 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iterator>

namespace ft {

	template<class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};

	template<class T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef std::random_access_iterator_tag	iterator_category;	
	};

	template<class T>
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef std::random_access_iterator_tag	iterator_category;	
	};

	template<class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};

	template <class Iterator>
	class reverse_iterator
	{
	protected:
		Iterator current;
	public:
		typedef Iterator												iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iterator>::value_type			value_type;
		typedef typename iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename iterator_traits<Iterator>::reference			reference;
		typedef typename iterator_traits<Iterator>::pointer				pointer;

		reverse_iterator()
		{ current = Iterator(); }
		explicit reverse_iterator(Iterator x)
		{ current = Iterator(x); }
		template <class U> 
		reverse_iterator(const reverse_iterator<U>& u)
		{ current = Iterator(u.base()); }

		Iterator base() const { return current; }
		reference operator*() const {
			Iterator	tmp = current;
			--tmp;
			return *tmp;
		}
		pointer operator->() const { return &(operator*()); }
		reverse_iterator& operator++() {
			--current;
			return *this;
		}
		reverse_iterator operator++(int) {
			reverse_iterator tmp = *this;
			--current;
			return tmp;
		}
		reverse_iterator& operator--() {
			++current;
			return *this;
		}
		reverse_iterator operator--(int) {
			reverse_iterator tmp = *this;
			++current;
			return tmp;
		}
		reverse_iterator operator+ (difference_type n) const
		{ return reverse_iterator(current - n); }
		reverse_iterator& operator+=(difference_type n) {
			current -= n;
			return *this;
		}
		reverse_iterator operator- (difference_type n) const {
			return reverse_iterator(current + n);
		}
		reverse_iterator& operator-=(difference_type n) {
			current += n;
			return *this;
		}
		reference operator[](difference_type n) const
		{ return current[-n - 1]; }

	};

	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{ return x.base() == y.base(); }
	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{ return x.base() > y.base(); }
	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{ return x.base() != y.base(); }
	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{ return x.base() < y.base(); }
	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{ return x.base() <= y.base(); }
	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{ return x.base() >= y.base(); }
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y) 
	{ return y.base() - x.base(); }

	template <class Iterator> reverse_iterator<Iterator> operator+(
		typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator>& x) 
	{ return reverse_iterator<Iterator>(x.base() - n); }

}
