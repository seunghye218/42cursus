/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_wrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:29:35 by seunghye          #+#    #+#             */
/*   Updated: 2023/02/01 15:26:51 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// #include <vector>
// #include <type_traits>
#include <algorithm>
#include <cstddef>
#include <memory>
#include "algorithm.hpp"
#include "iterator.hpp"
#include "type_traits.hpp"

namespace ft
{

template <class Iterator>
class wrap_iter
{
public:
	typedef Iterator													iterator_type;
	typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
	typedef typename iterator_traits<iterator_type>::value_type			value_type;
	typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
	typedef typename iterator_traits<iterator_type>::pointer			pointer;
	typedef typename iterator_traits<iterator_type>::reference			reference;
private:
    iterator_type it;
public:
    wrap_iter() {}
    
	template <class Up> 
	wrap_iter(const wrap_iter<Up>& u) : it(u.base()) {}

    reference operator*() const
    { return *it; }

	pointer		operator->() const
	{ return &(operator*()); }

    wrap_iter& operator++()  {
        ++it;
        return *this;
    }
    wrap_iter  operator++(int) {
		wrap_iter __tmp(*this);
		++(this->it);
		return __tmp;
	}
    wrap_iter& operator--() 
    {
        --it;
        return *this;
    }
    wrap_iter  operator--(int) 
	{wrap_iter __tmp(*this); --(*this); return __tmp;}
    wrap_iter  operator+ (difference_type __n) const 
	{wrap_iter __w(*this); __w += __n; return __w;}
    wrap_iter& operator+=(difference_type __n) 
    {
        it += __n;
        return *this;
    }
    wrap_iter  operator- (difference_type __n) const 
        {return *this + (-__n);}


    wrap_iter& operator-=(difference_type __n) 
	{*this += -__n; return *this;}
    reference        operator[](difference_type __n) const 
    { return it[__n]; }

    iterator_type base() const  {return it;}

    wrap_iter(iterator_type __x)  : it(__x) {}
private:
    // template <class _Up> friend class wrap_iter;
    // template <class _CharT, class _Traits, class _Alloc> friend class basic_string;
    
	// template <class _Tp, class _Alloc> friend class _LIBCPP_TYPE_VIS_ONLY ft::vector;
	// template <class _Tp, class _Alloc> friend class vector;

    template <class Iter1, class Iter2>
    friend
    bool	operator==(const wrap_iter<Iter1>&, const wrap_iter<Iter2>&);
    template <class Iter1, class Iter2>
    friend
    bool	operator<(const wrap_iter<Iter1>&, const wrap_iter<Iter2>&);
    template <class Iter1, class Iter2>
    friend
    typename wrap_iter<Iter1>::difference_type	operator-(const wrap_iter<Iter1>&, const wrap_iter<Iter2>&);
	// template <class Iter1, class Iter2>
    // friend
    // wrap_iter<Iter1>	operator-(const wrap_iter<Iter1>&, const wrap_iter<Iter2>&);
    template <class Iter1>
    friend
    wrap_iter<Iter1>	operator+(typename wrap_iter<Iter1>::difference_type, wrap_iter<Iter1>);
};

template <class Iter1, class Iter2>
bool	operator==(const wrap_iter<Iter1>& x, const wrap_iter<Iter2>& y) 
{ return x.base() == y.base(); }

template <class Iter1, class Iter2>
bool	operator<(const wrap_iter<Iter1>& x, const wrap_iter<Iter2>& y)
{ return x.base() < y.base(); }
template <class Iter1, class Iter2>
bool
operator!=(const wrap_iter<Iter1>& x, const wrap_iter<Iter2>& y)
{ return !(x == y); }
template <class Iter1, class Iter2>
bool
operator>(const wrap_iter<Iter1>& x, const wrap_iter<Iter2>& y)
{ return y < x; }
template <class Iter1, class Iter2>
bool
operator>=(const wrap_iter<Iter1>& x, const wrap_iter<Iter2>& y)
{ return !(x < y); }
template <class Iter1, class Iter2>
bool
operator<=(const wrap_iter<Iter1>& x, const wrap_iter<Iter2>& y)
{ return !(y < x); }

template <class Iter1, class Iter2>
typename wrap_iter<Iter1>::difference_type
operator-(const wrap_iter<Iter1>& x, const wrap_iter<Iter2>& y)
{ return x.base() - y.base(); }

// template <class Iter1, class Iter2>
// wrap_iter<Iter1>
// operator-(const wrap_iter<Iter1>& x, const wrap_iter<Iter2>& y)
// { return x.base() - y.base(); }

template <class Iter1>
wrap_iter<Iter1>
operator-(const typename wrap_iter<Iter1>::difference_type& n, const wrap_iter<Iter1>& x)
{ return x.base() - n; }

template <class Iter1>
wrap_iter<Iter1>
operator+(typename wrap_iter<Iter1>::difference_type n, wrap_iter<Iter1> x)
{ return x.base() + n; }


	template<typename T, typename Allocator = std::allocator<T> >
	class vector
	{
	public:
		// types:
		typedef T									value_type;
		typedef value_type&							reference;
		typedef const value_type&					const_reference;
		typedef Allocator							allocator_type;
		typedef size_t								size_type;
		typedef ptrdiff_t							difference_type;
		typedef value_type* 						pointer;
		typedef const value_type*					const_pointer;
		typedef wrap_iter<pointer>					iterator;
		typedef wrap_iter<const_pointer>			const_iterator;
		typedef reverse_iterator<const_iterator>    const_reverse_iterator;
		typedef reverse_iterator<iterator>          reverse_iterator;

		// 23.2.4.1 construct/copy/destroy:
		explicit vector(const Allocator& = Allocator())
		{ create(); }

		explicit vector(size_type n, const T& val = T(), const Allocator& = Allocator())
		{ create(n, val); }

		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const Allocator& = Allocator())
		{ create(first, last); }
		
		vector(const vector<T,Allocator>& x)
		{ create(x.begin(), x.end()); }
		~vector()
		{ destroy(); }
		vector<T,Allocator>&	operator=(const vector<T,Allocator>& x) {
			if (this != &x) {
				destroy();
				create(x.begin(), x.end());
			}
			return *this;
		}

		template <class InputIterator>
		void	assign(InputIterator first, InputIterator last
		, typename enable_if<!ft::is_integral<InputIterator>::value>::type* = 0
		) {
			size_type	n = last - first;
			if (n > capacity()) {
				vector<T, Allocator>	tmp(first, last);
				tmp.swap(*this);
			} else {
				// pointer it = m_begin;
				// while (it != m_end)
				// 	m_alloc.destroy(it++);
				clear();
				pointer	it = begin().base();
				for (; first != last; ++first)
					m_alloc.construct(it++, *first);
				m_end = m_begin + n;
			}
		}
		void	assign(size_type n, const T& u) {
			if (n > capacity()) {
				vector<T, Allocator>	tmp(n, u);
				tmp.swap(*this);
			} else if (n > size()) {
				std::fill(begin().base(), end().base(), u);
			} else 
				erase(std::fill_n(begin().base(), n, u), end());
		}

		allocator_type	get_allocator() const
		{ return m_alloc; }

		// iterators:
		iterator	begin()
		{ return m_begin; }
		const_iterator	begin() const
		{ return m_begin; }
		iterator	end()
		{ return m_end; }
		const_iterator	end()const
		{ return m_end; }
		reverse_iterator rbegin()
		{ return reverse_iterator(end()); }
// { return reverse_iterator(m_end); }
		const_reverse_iterator rbegin() const
		{ return const_reverse_iterator(end()); }
// { return const_reverse_iterator(m_end); }
		reverse_iterator rend()
		{ return reverse_iterator(begin()); }
// { return reverse_iterator(m_begin); }
		const_reverse_iterator rend() const
		{ return const_reverse_iterator(begin()); }
// { return const_reverse_iterator(m_begin); }

		// 23.2.4.2 capacity:
		size_type	size() const
		{ return static_cast<size_type>(m_end - m_begin); }
		size_type	max_size() const {
			return std::min<size_type>(m_alloc.max_size(),
										std::numeric_limits<difference_type>::max());
		}
		void	resize(size_type sz, T val = T())
		{
			size_type	cs = size();

			if (cs < sz) {
				if (capacity() * 2 < sz)
					reserve(sz);
				else if	(capacity() < sz)
					grow();
				std::uninitialized_fill(m_end, m_begin + sz, val);
				m_end = m_begin + sz;
			}
			else if (cs > sz) {
				pointer	it = m_begin + sz;
				while (it != m_end)
					m_alloc.destroy(it++);
				m_end = m_begin + sz;
			}
		}
		size_type	capacity() const
		{ return static_cast<size_type>(m_end_cap - m_begin); }
		bool	empty() const
		{ return this->m_begin == this->m_end; }
		void	reserve(size_type n) {
			if (n > capacity()) {
				pointer	tmp = m_alloc.allocate(n);
				pointer	tmp_end = std::uninitialized_copy(m_begin, m_end, tmp);

				destroy();
				m_begin = tmp;
				m_end = tmp_end;
				m_end_cap = m_begin + n;
			}
		}

		// element access:
		reference	operator[](size_type n)
		{ return *(m_begin + n); }
		const_reference	operator[](size_type n) const
		{ return *(m_begin + n); }
		reference	at(size_type n) {
			if (n > size())
				throw std::out_of_range("ft::vector::at");
			return *(m_begin + n);
		}
		const_reference	at(size_type n) const {
			if (n > size())
				throw std::out_of_range("ft::vector::at");
			return *(m_begin + n);
		}
		reference	front()
		{ return *m_begin; }
		const_reference	front() const
		{ return *m_begin; }
		reference	back()
		{ return *(m_end - 1); }
		const_reference	back() const
		{ return *(m_end - 1); }

		// 23.2.4.3 modifiers:
		// void	push_back(T x) {
		// 	if (m_end == m_end_cap)
		// 		grow();
		// 	m_alloc.construct(m_end++, x);
		// }

		void	push_back(const T& x) {
			if (m_end == m_end_cap)
				grow();
			m_alloc.construct(m_end++, x);
		}

		void	pop_back()
		{ m_alloc.destroy(--m_end); }

		iterator	insert(const_iterator position, const T& x) {
// pointer	position = _position.base();
			difference_type	idx = position.base() - m_begin;
			if (m_end == m_end_cap) {
				size_type	sz = std::min<size_type>(capacity() * 2, std::numeric_limits<difference_type>::max());
				// iterator	tmp_begin = m_alloc.allocate(sz);
				// iterator	tmp = std::uninitialized_copy(m_begin, position.base(), tmp_begin);
pointer	tmp_begin = m_alloc.allocate(sz);
pointer	tmp = std::uninitialized_copy(m_begin, position.base(), tmp_begin);

				m_alloc.construct(tmp, x);
				tmp = std::uninitialized_copy(position.base(), m_end, tmp + 1);
				destroy();
				m_begin = tmp_begin;
				m_end = tmp;
				m_end_cap = tmp_begin + sz;
			}
			else {
				if (position.base() == m_end) {
					grow();
					m_alloc.construct(m_end, x);
					++m_end;
				}
				else {
					// iterator	it = m_end++;
pointer 	it = m_end++;
					while (it != position.base()) {
						*it = *(it - 1);
						--it;
					}
					m_alloc.construct(position.base(), x);
				}
			}
			// return m_begin + idx;
			return iterator(m_begin + idx);
		}

		void	insert(const_iterator position, size_type n, const T& x) {
			if (n != 0) {
				// pointer	position = _position.base();
				if (n > size_type(m_end_cap - m_end)) {
					const size_type old_sz = size();
					const size_type sz = old_sz + std::max(old_sz, n);
					pointer new_begin = m_alloc.allocate(sz);
					pointer new_end = new_begin;
					try {
						new_end = std::uninitialized_copy(m_begin, position.base(), new_begin);
						new_end = std::uninitialized_fill_n(new_end, n, x);
						new_end = std::uninitialized_copy(position.base(), m_end, new_end);
					} catch (...) {
						pointer i = new_begin;
						while (i != new_end)
							m_alloc.destroy(i++);
						m_alloc.deallocate(new_begin, new_begin - new_end);
						throw ;
					}
					destroy();
					m_begin = new_begin;
					m_end = new_end;
					m_end_cap = new_begin + sz;
				} else {
					m_end += n;
					pointer	it = m_end;
					while (it != position.base()) {
						m_alloc.destroy(it);
						m_alloc.construct(it, *(it - n));
					}
					std::uninitialized_fill_n(position.base(), n, x);
				}
			}
		}
		template <class InputIterator>
		void	insert(const_iterator position, InputIterator first, InputIterator last
		, typename enable_if<!ft::is_integral<InputIterator>::value>::type* = 0
		)
		{
			size_type	n = last.base() - first.base();
			if (n > size_type(m_end_cap - m_end)) {
				const size_type old_sz = size();
				const size_type sz = old_sz + std::max(old_sz, n);
				pointer new_begin = m_alloc.allocate(sz);
				pointer new_end = new_begin;
				try {
					new_end = std::uninitialized_copy(m_begin, position.base(), new_begin);
					new_end = std::uninitialized_copy(first, last, new_end);
					new_end = std::uninitialized_copy(position.base(), m_end, new_end);
				} catch (...) {
					pointer	it = new_begin;
					while (it != new_end)
						m_alloc.destroy(it++);
					m_alloc.deallocate(new_begin, sz);
					throw ;
				}
				destroy();
				m_begin = new_begin;
				m_end = new_end;
				m_end_cap = new_begin + sz;
			}
			else {
				m_end += n;
				pointer	it = m_end;
				while (it != position.base()) {
					m_alloc.destroy(it);
					m_alloc.construct(it, *(it - n));
				}
				std::uninitialized_copy(first.base(), last.base(), position.base());
			}
		}

		iterator	erase(iterator position) {
			if (position.base() != m_end - 1)
				std::uninitialized_copy(position.base() + 1, m_end, position.base());
			m_alloc.destroy(position.base());
			--m_end;
			return position;
		}

		iterator	erase(iterator first, iterator last) {
			pointer it = std::copy(last.base(), m_end, first.base());
			while (it != m_end)
				m_alloc.destroy(it++);
			m_end -= (last.base() - first.base());
			return first;
			// return first.base();
		}

		void	swap(vector<T,Allocator>& v) {
			if (this != &v) {
				std::swap(m_begin, v.m_begin);
				std::swap(m_end, v.m_end);
				std::swap(m_end_cap, v.m_end_cap);
			}
		}
		void	clear()
		{ erase(begin(), end()); }

	private:
		pointer			m_begin;
		pointer			m_end;
		pointer			m_end_cap;
		allocator_type	m_alloc;

		void	create() { m_begin = m_end = m_end_cap = 0; }
		
		void	create(size_type n, const T& val) {
			m_begin = m_alloc.allocate(n);
			m_end = m_end_cap = m_begin + n;
			std::uninitialized_fill(m_begin, m_end_cap, val);
		}

		template <class InputIterator>
		void	create(InputIterator first, InputIterator last
		, typename enable_if<!ft::is_integral<InputIterator>::value>::type* = 0
		) {
			m_begin = m_alloc.allocate(last.base() - first.base());
			m_end = m_end_cap = std::uninitialized_copy(first.base(), last.base(), m_begin);
		}

		void	destroy(void) {
			if (m_begin) {
				pointer	i = m_begin;
				while (i != m_end)
					m_alloc.destroy(i++);
				m_alloc.deallocate(m_begin, m_end_cap - m_begin);
				m_begin = m_end = m_end_cap = 0;
			}
		}

		void grow(void) { reserve(capacity() * 2 > 0 ? capacity() * 2 : 1); }
	};

	template <class T, class Allocator>
	bool	operator== (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	// { return (x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin())); }
{ return (x.size() == y.size() && ft::equal(x.begin().base(), x.end().base(), y.begin().base())); }

	template <class T, class Allocator>
	bool	operator!= (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{ return !(x == y); }

	template <class T, class Allocator>
	bool	operator<  (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	// { return ft::lexicographical_compare(x.begin(), x.end(),
	// 									y.begin(), y.end()); }
{ return ft::lexicographical_compare(x.begin().base(), x.end().base(),
									y.begin().base(), y.end().base()); }

	template <class T, class Allocator>
	bool	operator<= (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{ return !(y < x); }
	template <class T, class Allocator>
	bool	operator>  (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{ return y < x; }
	template <class T, class Allocator>
	bool	operator>= (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{ return !(x < y); }

	template <class T, class Allocator>
	void	swap(vector<T,Allocator>& x, vector<T,Allocator>& y) {
		x.swap(y);
	}

}