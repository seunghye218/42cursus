/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:39:37 by seunghye          #+#    #+#             */
/*   Updated: 2023/02/07 15:11:17 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// #include <set>
#include <functional>
#include "algorithm.hpp"
#include "iterator.hpp"
#include "type_traits.hpp"
#include "utility.hpp"
#include "rb_tree.hpp"

namespace ft
{
	template <typename Value>
	struct	KeyOfValue_set : public std::unary_function<Value, Value>
	{ const Value& operator()(const Value& k) const { return k; } };
	
  	template <class Key, class Compare = std::less<Key>,
            class Allocator = std::allocator<Key> >
  	class set
	{
	private:

		typedef Tree<Key, Key, KeyOfValue_set<Key>, Compare, Allocator>	Rb_tree;
		Rb_tree												m_tree;
	public:
		// types:
		typedef Key											key_type;
		typedef Key											value_type;
		typedef Compare										key_compare;
		typedef Compare										value_compare;
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
		explicit set(const Compare& comp = Compare(), const Allocator& alloc = Allocator()) : m_tree(comp, alloc) {}
		
		template <class InputIterator>
   		set(InputIterator first, InputIterator last,
       		const Compare& comp = Compare(), const Allocator& alloc = Allocator()) : m_tree(first, last, comp, alloc) {}
		set(const set<Key,Compare,Allocator>& x) : m_tree(x.m_tree) {}
		~set() {}

		set<Key,Compare,Allocator>& operator=(const set<Key,Compare,Allocator>& x) {
			m_tree = x.m_tree;
            return *this;
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
		
		void								swap(set<Key,Compare,Allocator>& x)
		{ m_tree.swap(x.m_tree); }
		void								clear()
		{ m_tree.clear(); }

		// observers:
		key_compare		key_comp() const
		{ return m_tree.key_comp(); }
		value_compare	value_comp() const
		{ return m_tree.key_comp(); }
		
		// set operations:
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
	bool operator==(const set<Key,Compare,Allocator>& x,
							const set<Key,Compare,Allocator>& y)
	{ return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin()); }
	template <class Key, class Compare, class Allocator>
	bool operator< (const set<Key,Compare,Allocator>& x,
					const set<Key,Compare,Allocator>& y)
	{ return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()); }

	template <class Key, class Compare, class Allocator>
	inline bool operator!=(const set<Key,Compare,Allocator>& x,
					const set<Key,Compare,Allocator>& y)
	{ return !(x == y); }
	template <class Key, class Compare, class Allocator>
	inline bool operator> (const set<Key,Compare,Allocator>& x,
					const set<Key,Compare,Allocator>& y)
	{ return y < x; }
	template <class Key, class Compare, class Allocator>
	inline bool operator>=(const set<Key,Compare,Allocator>& x,
					const set<Key,Compare,Allocator>& y)
	{ return !(x < y); }
	template <class Key, class Compare, class Allocator>
	inline bool operator<=(const set<Key,Compare,Allocator>& x,
					const set<Key,Compare,Allocator>& y)
	{ return !(y < x); }

	// specialized algorithms:
	template <class Key, class Compare, class Allocator>
	inline void swap(set<Key,Compare,Allocator>& x,
				set<Key,Compare,Allocator>& y)
	{ x.swap(y); }
}
