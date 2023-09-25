/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:29:35 by seunghye          #+#    #+#             */
/*   Updated: 2023/02/01 18:05:21 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// #include <cstddef>
#include <memory>
#include <algorithm>
#include <cstddef>
#include "algorithm.hpp"
#include "iterator.hpp"
#include "type_traits.hpp"

namespace ft
{
	template<typename T, typename Allocator = std::allocator<T> >
	class vector
	{
	public:
		// types:
		typedef T										value_type;
		typedef value_type&								reference;
		typedef const value_type&						const_reference;
		typedef Allocator								allocator_type;
		typedef size_t									size_type;
		typedef ptrdiff_t								difference_type;
		typedef value_type*								pointer;
		typedef const value_type*						const_pointer;
		typedef value_type*								iterator;
		typedef const value_type*						const_iterator;
		typedef reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef reverse_iterator<iterator>				reverse_iterator;

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
				clear();
				pointer	it = begin();
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
				std::fill(begin(), end(), u);
			} else 
				erase(std::fill_n(begin(), n, u), end());
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
		const_reverse_iterator rbegin() const
		{ return const_reverse_iterator(end()); }
		reverse_iterator rend()
		{ return reverse_iterator(begin()); }
		const_reverse_iterator rend() const
		{ return const_reverse_iterator(begin()); }

		// 23.2.4.2 capacity:
		size_type	size() const
		{ return static_cast<size_type>(m_end - m_begin); }
		size_type	max_size() const 
		{ return std::min<size_type>(m_alloc.max_size(), size_type(-1) / sizeof(T)); }
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
				iterator	it = m_begin + sz;
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
				iterator	tmp = m_alloc.allocate(n);
				iterator	tmp_end = std::uninitialized_copy(m_begin, m_end, tmp);

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
		void	push_back(const T& x) {
			if (m_end == m_end_cap)
				grow();
			m_alloc.construct(m_end++, x);
		}
		void	pop_back()
		{ m_alloc.destroy(--m_end); }

		iterator	insert(iterator position, const T& x) {
			difference_type	idx = position - m_begin;
			if (m_end == m_end_cap) {
				size_type	sz = std::min<size_type>(capacity() * 2, std::numeric_limits<difference_type>::max());
				iterator	tmp_begin = m_alloc.allocate(sz);
				iterator	tmp = std::uninitialized_copy(m_begin, position, tmp_begin);
				m_alloc.construct(tmp, x);
				tmp = std::uninitialized_copy(position, m_end, tmp + 1);

				destroy();
				m_begin = tmp_begin;
				m_end = tmp;
				m_end_cap = tmp_begin + sz;
			}
			else {
				if (position == m_end) {
					grow();
					m_alloc.construct(m_end, x);
					++m_end;
				}
				else {
					iterator	it = m_end++;
					while (it != position) {
						*it = *(it - 1);
						--it;
					}
					m_alloc.construct(position, x);
				}
			}
			return m_begin + idx;
		}
		void	insert(iterator position, size_type n, const T& x) {
			if (n != 0) {
				if (n > size_type(m_end_cap - m_end)) {
					const size_type old_sz = size();
					const size_type sz = old_sz + std::max(old_sz, n);
					pointer new_begin = m_alloc.allocate(sz);
					pointer new_end = new_begin;
					try {
						new_end = std::uninitialized_copy(m_begin, position, new_begin);
						new_end = std::uninitialized_fill_n(new_end, n, x);
						new_end = std::uninitialized_copy(position, m_end, new_end);
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
					const size_type elems_after = m_end - position;
					iterator old_end = m_end;
					if (elems_after > n) {
						std::uninitialized_copy(m_end - n, m_end, m_end);
						m_end += n;
						std::copy_backward(position, old_end - n, old_end);
        				std::fill(position, position + n, x);
					} else {
						std::uninitialized_fill_n(m_end, n - elems_after, x);
						m_end += n - elems_after;
						std::uninitialized_copy(position, old_end, m_end);
						m_end += elems_after;
						std::fill(position, old_end, x);
					}
				}
			}
		}
		template <class InputIterator>
		void	insert(iterator position, InputIterator first, InputIterator last
		, typename enable_if<!ft::is_integral<InputIterator>::value>::type* = 0
		) {
			size_type	n = size_type(last - first);
			if (n > size_type(m_end_cap - m_end)) {
				const size_type old_sz = size();
				const size_type sz = old_sz + std::max(old_sz, n);
				pointer new_begin = m_alloc.allocate(sz);
				pointer new_end = new_begin;
				try {
					new_end = std::uninitialized_copy(m_begin, position, new_begin);
					new_end = std::uninitialized_copy(first, last, new_end);
					new_end = std::uninitialized_copy(position, m_end, new_end);
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
				const size_type elems_after = m_end - position;
				iterator old_end = m_end;
				if (elems_after > n) {
					std::uninitialized_copy(m_end - n, m_end, m_end);
					m_end += n;
					std::copy_backward(position, old_end - n, old_end);
					std::copy(first, last, position);
				} else {
					std::uninitialized_copy(first + elems_after, last, m_end);
					m_end += n - elems_after;
					std::uninitialized_copy(position, old_end, m_end);
					m_end += elems_after;
					std::copy(first, first + elems_after, position);
				}
			}
		}

		iterator	erase(iterator position) {
			m_alloc.destroy(position);
			std::uninitialized_copy(position + 1, m_end, position);
			m_alloc.destroy(m_end);
			--m_end;
			return position;
		}
		iterator	erase(iterator first, iterator last) {
			pointer it = std::copy(last, m_end, first);
			while (it != m_end)
				m_alloc.destroy(it++);
			m_end -= last - first;
			return first;
		}
		void	swap(vector<T,Allocator>& v) {
			iterator	tmp_begin = m_begin;
			iterator	tmp_end = m_end;
			iterator	tmp_end_cap = m_end_cap;

			m_begin = v.m_begin;
			m_end = v.m_end;
			m_end_cap = v.m_end_cap;

			v.m_begin = tmp_begin;
			v.m_end = tmp_end;
			v.m_end_cap = tmp_end_cap;
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
		void	create(InputIterator first, InputIterator last,
		typename enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) {
			m_begin = m_alloc.allocate(last - first);
			m_end = m_end_cap = std::uninitialized_copy(first, last, m_begin);
		}

		void	destroy(void) {
			if (m_begin) {
				iterator	i = m_end;
				while (i != m_begin)
					m_alloc.destroy(--i);
				m_alloc.deallocate(m_begin, m_end_cap - m_begin);
				m_begin = m_end = m_end_cap = 0;
			}
		}

		void grow(void) { reserve(capacity() * 2 > 0 ? capacity() * 2 : 1); }
	};

	template <class T, class Alloc>
	bool	operator== (const vector<T,Alloc>& x, const vector<T,Alloc>& y)
	{ return (x.size() == y.size() && std::equal(x.begin(), x.end(), y.begin())); }

	template <class T, class Alloc>
	bool	operator!= (const vector<T,Alloc>& x, const vector<T,Alloc>& y)
	{ return !(x == y); }

	template <class T, class Alloc>
	bool	operator<  (const vector<T,Alloc>& x, const vector<T,Alloc>& y)
	{ return ft::lexicographical_compare(x.begin(), x.end(),
										y.begin(), y.end()); }

	template <class T, class Alloc>
	bool	operator<= (const vector<T,Alloc>& x, const vector<T,Alloc>& y)
	{ return !(y < x); }
	template <class T, class Alloc>
	bool	operator>  (const vector<T,Alloc>& x, const vector<T,Alloc>& y)
	{ return y < x; }
	template <class T, class Alloc>
	bool	operator>= (const vector<T,Alloc>& x, const vector<T,Alloc>& y)
	{ return !(x < y); }

	template <class T, class Alloc>
	void	swap(vector<T,Alloc>& x, vector<T,Alloc>& y) {
		x.swap(y);
	}
}
