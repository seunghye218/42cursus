/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:49:48 by seunghye          #+#    #+#             */
/*   Updated: 2023/02/07 15:12:36 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// #include <map>
#include <functional>
#include "algorithm.hpp"
#include "iterator.hpp"
#include "type_traits.hpp"
#include "utility.hpp"
#include "rb_tree.hpp"

namespace ft
{
	template <typename Pair>
	struct	KeyOfValue_map
	: public std::unary_function<const Pair&, typename Pair::first_type> {
		typename Pair::first_type& operator()(Pair& p) const
		{ return p.first; }

		const typename Pair::first_type& operator()(const Pair& p) const
		{ return p.first; }
	};

  	template <class Key, class Value, class Compare = std::less<Key>,
            class Allocator = std::allocator<pair<const Key, Value> > >
  	class map
	{
	public:
		// types:
		typedef Key									key_type;
		typedef Value								mapped_type;
		typedef pair<const key_type, mapped_type>	value_type;
		typedef Compare								key_compare;

		class value_compare : public std::binary_function<value_type,value_type,bool> {
			friend class map;
		protected:
			Compare comp;
			value_compare(Compare c) : comp(c) {}
		public:
			bool operator()(const value_type& x, const value_type& y) const
			{ return comp(x.first, y.first); } 
		};

	private:
		typedef Tree<key_type, value_type, KeyOfValue_map<value_type>, key_compare, Allocator>	Rb_tree;
		Rb_tree										m_tree;
	public:
		typedef typename Rb_tree::allocator_type			allocator_type;
		typedef typename Rb_tree::reference					reference;
		typedef typename Rb_tree::const_reference			const_reference;
		typedef typename Rb_tree::size_type					size_type;
		typedef typename Rb_tree::difference_type			difference_type;
		typedef typename Rb_tree::pointer					pointer;
		typedef typename Rb_tree::const_pointer				const_pointer;
		typedef typename Rb_tree::iterator					iterator;
		typedef typename Rb_tree::const_iterator			const_iterator;
		typedef typename Rb_tree::reverse_iterator			reverse_iterator;
		typedef typename Rb_tree::const_reverse_iterator	const_reverse_iterator;
		
		// 23.3.3.1 construct/copy/destroy:
		explicit map(const Compare& comp = Compare(), const Allocator& alloc = Allocator()) : m_tree(comp, alloc) {}
		template <class InputIterator>
   		map(InputIterator first, InputIterator last,
       		const Compare& comp = Compare(), const Allocator& alloc = Allocator()) : m_tree(first, last, comp, alloc) {}
		map(const map<Key,Compare,Allocator>& x) : m_tree(x.m_tree) {}
		~map() {}
 		
		map<Key,Compare,Allocator>& operator=(const map<Key,Compare,Allocator>& x) {
			m_tree = x.m_tree;
            return *this;
        }

		Value& operator[](const key_type& k) {
			iterator it = lower_bound(k);
			// it->first is greater than or equivalent to k.
			if (it == end() || key_comp()(k, (*it).first))
				it = insert(it, value_type(k, Value()));
		return (*it).second;
		}

		allocator_type	get_allocator() const
		{ return m_tree.get_allocator(); }

		// iterators:
		iterator					begin()
		{ return m_tree.begin(); }
		const_iterator				begin() const
		{ return m_tree.begin(); }
		iterator					end()
		{ return m_tree.end(); }
		const_iterator				end() const
		{ return m_tree.end(); }
		reverse_iterator			rbegin()
		{ return m_tree.rbegin(); }
		const_reverse_iterator		rbegin() const
		{ return m_tree.rbegin(); }
		reverse_iterator			rend()
		{ return m_tree.rend(); }
		const_reverse_iterator		rend() const
		{ return m_tree.rend(); }

		// capacity:
		bool						empty() const
		{ return m_tree.empty(); }
		size_type					size() const
		{ return m_tree.size(); }
		size_type					max_size() const
		{ return m_tree.max_size(); }

		// modifiers:
		pair<iterator,bool>					insert(const value_type& x)
		{ return m_tree.insert_unique(x); }
		iterator							insert(iterator position, const value_type& x)
		{ return m_tree.insert_unique(position, x); }
		template <class InputIterator>
		void								insert(InputIterator first, InputIterator last)
		{ return m_tree.insert_unique(first, last); }

		void								erase(iterator position)
		{ return m_tree.erase(position); }
		size_type							erase(const key_type& x)
		{ return m_tree.erase(x); }
		void								erase(iterator first, iterator last)
		{ return m_tree.erase(first, last); }
		
		void								swap(map<Key, Value, Compare, Allocator>& x)
		{ m_tree.swap(x.m_tree); }
		void								clear()
		{ m_tree.clear(); }

		// observers:
		key_compare		key_comp() const
		{ return m_tree.key_comp(); }
		value_compare	value_comp() const
		{ return value_compare(m_tree.key_comp()); }
		
		// map operations:
		size_type							count(const key_type& x) const
		{ return m_tree.count(x); }
		iterator							find(const key_type& x)
		{ return m_tree.find(x); }
		const_iterator						find(const key_type& x) const
		{ return m_tree.find(x); }
		iterator							lower_bound(const key_type& x)
		{ return m_tree.lower_bound(x); }
		const_iterator						lower_bound(const key_type& x) const
		{ return m_tree.lower_bound(x); }
		iterator							upper_bound(const key_type& x)
		{ return m_tree.upper_bound(x); }
		const_iterator						upper_bound(const key_type& x) const
		{ return m_tree.upper_bound(x); }
		pair<iterator,iterator>				equal_range(const key_type& x)
		{ return m_tree.equal_range(x); }
		pair<const_iterator,const_iterator>	equal_range(const key_type& x) const
		{ return m_tree.equal_range(x); }
	};

	template <class Key, class Compare, class Allocator>
	inline bool	operator==(const map<Key,Compare,Allocator>& x,
					const map<Key,Compare,Allocator>& y)
	{ return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin()); }
	template <class Key, class Compare, class Allocator>
	inline bool	operator< (const map<Key,Compare,Allocator>& x,
					const map<Key,Compare,Allocator>& y)
	{ return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()); }
	template <class Key, class Compare, class Allocator>
	inline bool operator!=(const map<Key,Compare,Allocator>& x,
					const map<Key,Compare,Allocator>& y)
	{ return !(x == y); }
	template <class Key, class Compare, class Allocator>
	inline bool operator> (const map<Key,Compare,Allocator>& x,
					const map<Key,Compare,Allocator>& y)
	{ return y < x; }
	template <class Key, class Compare, class Allocator>
	inline bool operator>=(const map<Key,Compare,Allocator>& x,
					const map<Key,Compare,Allocator>& y)
	{ return !(x < y); }
	template <class Key, class Compare, class Allocator>
	inline bool operator<=(const map<Key,Compare,Allocator>& x,
					const map<Key,Compare,Allocator>& y)
	{ return !(y < x); }

	// specialized algorithms:
	template <class Key, class Compare, class Allocator>
	inline void swap(map<Key,Compare,Allocator>& x,
				map<Key,Compare,Allocator>& y)
	{ x.swap(y); }
}
