/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:41:13 by seunghye          #+#    #+#             */
/*   Updated: 2023/02/07 16:02:51 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// #include <set>
// #include <map>
// #include <algorithm>
// #include <__tree>
// #include <iostream>
#include <functional>
#include <memory>
#include "type_traits.hpp"
#include "iterator.hpp"
#include "utility.hpp"


namespace ft
{

	typedef bool rb_tree_color;
	const rb_tree_color RED = false;
	const rb_tree_color BLACK = true;

	template <typename Value>
	struct node
	{
		Value				value;
		rb_tree_color		color;
		node<Value>*		parent;
		node<Value>*		left;
		node<Value>*		right;
	};

	template <typename Value, typename Ref, typename Ptr>
	struct Tree_iterator
	{
  		typedef std::bidirectional_iterator_tag							iterator_category;
		typedef ptrdiff_t											difference_type;
		typedef Value 												value_type;
		typedef Ref 												reference;
		typedef Ptr 												pointer;
		typedef Tree_iterator<Value, Value&, Value*>				iterator;
		typedef Tree_iterator<Value, const Value&, const Value*>	const_iterator;
		typedef Tree_iterator<Value, Ref, Ptr>						Self;
		typedef struct node<Value>*									Link_type;

		Link_type	m_node;

		Tree_iterator() {}
		Tree_iterator(Link_type node)
		{ m_node = node; }
		Tree_iterator(const iterator& it)
		{ m_node = it.m_node; }
		~Tree_iterator() {}


		reference	operator*() const
		{ return m_node->value; }
		pointer		operator->() const
		{ return &(operator*()); }

		void	increment() {
			if (m_node->right != 0) {
				m_node = m_node->right;
				while (m_node->left != 0)
					m_node = m_node->left;
			} else { 
				Link_type	p = m_node->parent;
				while (m_node == p->right) {
					m_node = p;
					p = p->parent;
				}
				if (m_node->right != p)
					m_node = p;
			}
		}

		void	 decrement() {
			if (m_node->color == RED && m_node->parent->parent == m_node)
				m_node = m_node->right;
			else if (m_node->left != 0) {
				m_node = m_node->left;
				while (m_node->right != 0)
					m_node = m_node->right;
			} else { 
				Link_type	p = m_node->parent;
				while (m_node == p->left) {
					m_node = p;
					p = p->parent;
				}
				m_node = p;
			}
		}

		Self& operator++() { 
			increment();
			return *this; 
		}
		Self operator++(int) {
			Self	tmp = *this;
    		increment();
    		return tmp;
  		}
		Self& operator--() { 
			decrement();
			return *this; 
		}
		Self operator--(int) {
			Self	tmp = *this;
    		decrement();
    		return tmp;
  		}
	};

	template <typename Value, typename Ref, typename Ptr>
	inline bool operator==(const Tree_iterator<Value, Ref, Ptr> x, 
							const Tree_iterator<Value, Ref, Ptr> y)
	{ return x.m_node == y.m_node; }
	template <class Value>
	inline bool operator==(const Tree_iterator<Value, const Value&, const Value*>& x,
							const Tree_iterator<Value, Value&, Value*>& y)
	{ return x.m_node == y.m_node; }
	template <class Value>
	inline bool operator==(const Tree_iterator<Value, Value&, Value*>& x,
							const Tree_iterator<Value, const Value&, const Value*>& y)
	{ return x.m_node == y.m_node; }

	template <class Value, class Ref, class Ptr>
	inline bool operator!=(const Tree_iterator<Value, Ref, Ptr>& x,
							const Tree_iterator<Value, Ref, Ptr>& y)
	{ return x.m_node != y.m_node; }
	template <class Value>
	inline bool operator!=(const Tree_iterator<Value, const Value&, const Value*>& x,
							const Tree_iterator<Value, Value&, Value*>& y)
	{ return x.m_node != y.m_node; }
	template <class Value>
	inline bool operator!=(const Tree_iterator<Value, Value&, Value*>& x,
							const Tree_iterator<Value, const Value&, const Value*>& y)
	{ return x.m_node != y.m_node; }

template <
typename Key,
typename Value,
typename KeyOfValue,
typename Compare = std::less<Key>,
typename Allocator = std::allocator<Value> >
	class Tree
	{
	public:
		typedef Key 				key_type;
		typedef Value				value_type;
		typedef Compare				value_compare;
		typedef Allocator			allocator_type;
		typedef value_type* 		pointer;
		typedef const value_type* 	const_pointer;
		typedef value_type& 		reference;
		typedef const value_type& 	const_reference;
		typedef size_t 				size_type;
		typedef ptrdiff_t 			difference_type;
		typedef struct node<value_type>*	Link_type;

		typedef Tree_iterator<value_type, reference, pointer>				iterator;
		typedef Tree_iterator<value_type, const_reference, const_pointer>	const_iterator;
		typedef reverse_iterator<const_iterator>							const_reverse_iterator;
  		typedef reverse_iterator<iterator>									reverse_iterator;

		explicit Tree(const Compare& comp = Compare(), const allocator_type& alloc = allocator_type())
		: m_compare(comp), m_node_alloc(alloc)
		{ _empty_init(); }

		template <class InputIterator>
		Tree(InputIterator first, InputIterator last, 
			const Compare& comp = Compare(), const allocator_type& alloc = allocator_type()) 
		: m_compare(comp), m_node_alloc(alloc) { 
			_empty_init();
			insert_unique(first, last);
		}
		
		Tree(const Tree& x)
		: m_node_alloc(x.get_allocator()) { 
			_empty_init();
			m_compare = x.m_compare;
		}
		
		~Tree() {
			clear();
			_delete_node(m_header);
		}

		Tree&	operator=(const Tree& t) {
			if (this != &t) {
				clear();
				m_cnt = 0;
				m_compare = t.m_compare;        
				if (t._root() == 0) {
					_root() = 0;
					_leftmost() = m_header;
					_rightmost() = m_header;
				} else {
					_root() = _copy_subtree(t._root(), m_header);
					_leftmost() = _minimum(_root());
					_rightmost() = _maximum(_root());
					m_cnt = t.m_cnt;
				}
			}
			return *this;
		}


		Compare key_comp() const 
		{ return m_compare; }
		iterator begin()
		{ return m_header->left; }
		const_iterator begin() const
		{ return m_header->left;; }
		iterator end()
		{ return m_header; }
		const_iterator end() const
		{ return m_header; }
		reverse_iterator rbegin()
		{ return reverse_iterator(end()); }
		const_reverse_iterator rbegin() const
		{ return const_reverse_iterator(end()); }
		reverse_iterator rend()
		{ return reverse_iterator(begin()); }
		const_reverse_iterator rend() const
		{  return const_reverse_iterator(begin()); } 
		bool empty() const
		{ return m_cnt == 0; }
		size_type size() const
		{ return m_cnt; }
		size_type max_size() const
		{ return size_type(-1); }
		allocator_type	get_allocator() const
		{ return m_node_alloc; }

		iterator	find(Key key) {
			Link_type	cur = m_header;
			Link_type	cur_c = _root();
			bool		comp = true;

			while (cur_c != 0) {
				cur = cur_c;
				comp = m_compare(key, KeyOfValue()(cur_c->value));
				if (comp)
					cur_c = cur_c->left;
				else if (comp != m_compare(KeyOfValue()(cur_c->value), key))
					cur_c = cur_c->right;
				else
				 	return iterator(cur_c);
			}
			return end();
		}

		const_iterator	find(Key key) const {
			Link_type	cur = m_header;
			Link_type	cur_c = _root();
			bool		comp = true;

			while (cur_c != 0) {
				cur = cur_c;
				comp = m_compare(key, KeyOfValue()(cur_c->value));
				if (comp)
					cur_c = cur_c->left;
				else if (comp != m_compare(KeyOfValue()(cur_c->value), key))
					cur_c = cur_c->right;
				else
				 	return iterator(cur_c);
			}
			return end();
		}

		size_type count(const key_type& key) const
		{ return find(key) != end() ? 1 : 0; }

		iterator lower_bound(const key_type& key) {
			Link_type cur = m_header;
			Link_type cur_c = _root();
			while (cur_c != 0) {
				if (!m_compare(KeyOfValue()(cur_c->value), key)) {
					cur = cur_c;
					cur_c = cur_c->left;
				} else
					cur_c = cur_c->right;
			}
			return iterator(cur);
		}

		const_iterator lower_bound(const key_type& key) const {
			Link_type cur = m_header;
			Link_type cur_c = _root();
			while (cur_c != 0) {
				if (!m_compare(KeyOfValue()(cur_c->value), key)) {
					cur = cur_c;
					cur_c = cur_c->left;
				} else
					cur_c = cur_c->right;
			}
			return iterator(cur);
		}

		iterator upper_bound(const key_type& key) {
			Link_type cur = m_header;
			Link_type cur_c = _root();

			while (cur_c != 0) {
				if (m_compare(key, KeyOfValue()(cur_c->value))) {
					cur = cur_c;
					cur_c = cur_c->left;
				} else
					cur_c = cur_c->right;
			}
			return iterator(cur);
		}

		const_iterator upper_bound(const key_type& key) const {
			Link_type cur = m_header;
			Link_type cur_c = _root();

			while (cur_c != 0) {
				if (m_compare(key, KeyOfValue()(cur_c->value))) {
					cur = cur_c;
					cur_c = cur_c->left;
				} else
					cur_c = cur_c->right;
			}
			return iterator(cur);
		}

		pair<iterator, iterator>	equal_range(const key_type& key)
		{ return pair<iterator, iterator>(lower_bound(key), upper_bound(key)); }

		pair<const_iterator, const_iterator>	equal_range(const key_type& key) const
		{ return pair<const_iterator, const_iterator>(lower_bound(key), upper_bound(key)); }

		void clear() {
			if (m_cnt != 0) {
			_erase_subtree(_root());
			_leftmost() = m_header;
			_root() = 0;
			_rightmost() = m_header;
			m_cnt = 0;
			}
		}

		void swap(Tree<Key, Value, KeyOfValue, Compare, Allocator>& tree) {
			std::swap(m_header, tree.m_header);
			std::swap(m_cnt, tree.m_cnt);
			std::swap(m_compare, tree.m_compare);
		}

	protected:
		typedef	typename Allocator::template 
		rebind<struct node<value_type> >::other	Node_allocator;

		Link_type	_get_node() {
			Link_type    n = m_node_alloc.allocate(1);
			return n;
		}

		Link_type	_constuct_node(const value_type& value) {
			Link_type    n = _get_node();
			m_value_alloc.construct(&(n->value), value);
			return n;
		}

		void	_delete_node(Link_type n)
		{ return m_node_alloc.deallocate(n, 1); }

		void	_destroy_node(Link_type n) {
			m_value_alloc.destroy(&n->value);
			_delete_node(n);
		}

		void	_empty_init() {
			m_header = _get_node();
			m_header->color = RED;
			m_header->left = m_header;
			m_header->right = m_header;
			m_header->parent = 0;
			m_cnt = 0;
		}

		Link_type	_minimum(Link_type n) {
			while (n->left != 0)
				n = n->left;
			return n;
		}

		Link_type	_maximum(Link_type n) {
			while (n->right != 0)
				n = n->right;
			return n;
		}

		Link_type	_clone_node(Link_type x) {
			Link_type tmp = _constuct_node(x->value);
			tmp->color = x->color;
			tmp->left = 0;
			tmp->right = 0;
			return tmp;
		}

		Link_type	_copy_subtree(Link_type x, Link_type p) {
			Link_type top = _clone_node(x);
			top->parent = p;

			if (x->right)
				top->right = _copy_subtree(x->right, top);
			p = top;
			x = x->left;
			while (x != 0) {
				Link_type y = _clone_node(x);
				p->left = y;
				y->parent = p;
				if (x->right)
					y->right = _copy_subtree(x->right, y);
				p = y;
				x = x->left;
			}
			return top;
		}

		void	_erase_subtree(Link_type x) {
			Link_type	y;

			while (x != 0) {
				_erase_subtree(x->right);
				y = x->left;
				_destroy_node(x);
				x = y;
			}
		}

		Link_type&	_root() 
		{ return m_header->parent; }
		Link_type& _root() const
		{ return m_header->parent; }
		Link_type&	_leftmost() 
		{ return m_header->left; }
		Link_type&	_rightmost() 
		{ return m_header->right; }
		static const Key& _key(Link_type x)
		{ return KeyOfValue()(x->value); }

		Link_type _grandparent(Link_type n) {
			if ((n != m_header) && (n->parent != m_header) && (n->parent->parent != m_header))
				return n->parent->parent;
			else
				return 0;
		}

		Link_type _uncle(Link_type n) {
			Link_type g = _grandparent(n);
			if (g == 0)
				return 0;
			if (n->parent == g->left)
				return g->right;
			else
				return g->left;
		}

		void _rotate_left(Link_type n)
		{
			Link_type c = n->right;

			if (c->left != 0)
				c->left->parent = n;
			n->right = c->left;
			c->left = n;
			c->parent = n->parent;

			if (n == _root()) 
				_root() = c;
			else if (n->parent->left == n)
				n->parent->left = c;
			else
				n->parent->right = c;
			n->parent = c;
		}

		void _rotate_right(Link_type n)
		{
			Link_type c = n->left;

			if (c->right != 0)
				c->right->parent = n;
			n->left = c->right;
			c->right = n;
			c->parent = n->parent;
			if (n == _root())
				_root() = c;
			else if (n->parent->right == n)
				n->parent->right = c;
			else
				n->parent->left = c;
			n->parent = c;
		}

		Link_type	_sibling(Link_type n) {
			if (n == n->parent->left)
				return n->parent->right;
			else
				return n->parent->left;
		}

		bool	_is_left_child(Link_type n)
		{ return !n->parent || n == n->parent->right ? false : true; }

	private:
		// insert, erase helper

		iterator	_insert(Link_type x, Link_type y, const Value& value) {
			Link_type _x = x;
			Link_type _y = y;
			Link_type _z = _constuct_node(value);
			// if (root == null(초기 상태)|| 
			// 반복자 리턴 insert 함수일 때 삽입할 노드가 최소값일 떄  ||
			// value가 부모->value 보다 작을 때)
			if (_y == m_header || _x != 0 || 
				m_compare(KeyOfValue()(value), KeyOfValue()(_y->value))) {
				_y->left = _z;
				if (_y == m_header) {
					_root() = _z;
					_rightmost() = _z;
				} else if (_y == _leftmost())
					_leftmost() = _z;
			} else {
				_y->right = _z;
				if (_y == _rightmost())
					_rightmost() = _z; 
  			}
			_z->parent = _y;
			_z->left = 0;
			_z->right = 0;
			_z->color = RED;
			rb_insert_rebalance(_z);
			++m_cnt;
			return iterator(_z);
		}

		void rb_insert_rebalance(Link_type& n) {
			// if (n->parent == NULL)
			if (n->parent == m_header)
				n->color = BLACK;
			else if (n->parent->color == BLACK)
				return;
			else {
				Link_type	g = _grandparent(n);
				Link_type	u = _uncle(n);
				if ((u != NULL) && (u->color == RED)) {
					n->parent->color = BLACK;
					u->color = BLACK;
					g->color = RED;
					rb_insert_rebalance(g);
				} else {
					if ((n == n->parent->right) && (n->parent == g->left)) {
						_rotate_left(n->parent);
						n = n->left;
					} else if ((n == n->parent->left) && (n->parent == g->right)) {
						_rotate_right(n->parent);
						n = n->right;
					}
					n->parent->color = BLACK;
					g->color = RED;
					if (n == n->parent->left)
						_rotate_right(g);
					else
						_rotate_left(g);
				}
			}
			_root()->color = BLACK;
		}

		void	_rb_delete_case(Link_type x) {
			// delete_case1
			if (x != _root())
				return ;
			// delete_case2
			Link_type s = _sibling(x);
			if (s->color == RED) {
				x->parent->color = RED;
				s->color = BLACK;
				if (_is_left_child(x))
					_rotate_left(x->parent);
				else
					_rotate_right(x->parent);
			}
			// delete_case3
			s = _sibling(x);
			if ((x->parent->color == BLACK) &&
				(s->color == BLACK) &&
				(s->left == 0 || s->left->color == BLACK) &&
				(s->right == 0 || s->right->color == BLACK)) {
				s->color = RED;
				_rb_delete_case(x->parent);
			}
			// delete_case4
			s = _sibling(x);
			if ((x->parent->color == RED)&&
				(s->color == BLACK) &&
				(s->left == 0 || s->left->color == BLACK) &&
				(s->right == 0 || s->right->color == BLACK)) {
				s->color = RED;
				x->parent->color = BLACK;
				return ;
			}
			// delete_case5
			s = _sibling(x);
			if (s->color == BLACK) {
				if (_is_left_child(x) &&
					(s->right == 0 || s->right->color == BLACK) &&
					(s->left->color == RED)) {
					s->color = RED;
					s->left->color = BLACK;
					_rotate_right(s);
				} else if (!_is_left_child(x) && (s->left == 0 || s->left->color == BLACK) &&
						(s->right->color == RED)) {
					s->color = RED;
					s->right->color = BLACK;
					_rotate_left(s);
				}
			}
			// delete_case6
			s = _sibling(x);
			s->color = x->parent->color;
			x->parent->color = BLACK;
			if (_is_left_child(x)) {
				if (s->right) s->right->color = BLACK;
					_rotate_left(x->parent);
			} else {
				if (s->left) s->left->color = BLACK;
					_rotate_right(x->parent);
			}
		}

		Link_type	_rb_erase_rebalance(Link_type z) {
			Link_type y = z;
			Link_type x = 0;
			Link_type x_parent = 0;

			if (y->left == 0)
				x = y->right;
			else if (y->right == 0)
				x = y->left;
			else {
				y = y->right;
				while (y->left != 0)
					y = y->left;
				x = y->right;
			}

			if (y != z) {
				z->left->parent = y; 
				y->left = z->left;
				if (y != z->right) {
					x_parent = y->parent;
					if (x)
						x->parent = y->parent;
					y->parent->left = x;
					y->right = z->right;
					z->right->parent = y;
				} else
					x_parent = y;  
				if (_root() == z)
					_root() = y;
				else if (z->parent->left == z)
					z->parent->left = y;
				else 
					z->parent->right = y;
				y->parent = z->parent;
				std::swap(y->color, z->color);
				y = z;
			}
			else {
				x_parent = y->parent;
				if (x)
					x->parent = y->parent;   
				if (_root() == z)
						_root() = x;
				else 
					if (z->parent->left == z)
						z->parent->left = x;
					else
						z->parent->right = x;
				if (_leftmost() == z) {
					if (z->right == 0)
						_leftmost() = z->parent;
					else
						_leftmost() = _minimum(x);
				} if (_rightmost() == z) {
					if (z->left == 0)
						_rightmost() = z->parent;  
					else
						_rightmost() = _maximum(x);
				}
			}

			if (y->color == BLACK) {
				if (x && x->color == RED) {
					x->color = BLACK;
					return y;
				}
			} else 
				_rb_delete_case(x);
			return y;
		}

	public:
		// insert, erase

		// Compare를 사용하며 삽입할 위치의 부모 노드를 _insert의 인자로 넘김
		pair<iterator, bool>
		insert_unique(const Value& value) {
			// cur_c가 null 이라면 _insert 함수의 인자로 m_header로 들어가고 아니라면 삽입될 노드가 들어감
			Link_type	cur = m_header;
			// 항상 _insert 인자로 null로 들어감
			Link_type	cur_c = _root();
			bool		comp = true;

			while (cur_c != 0) {
				cur = cur_c;
				comp = m_compare(KeyOfValue()(value), KeyOfValue()(cur_c->value));
				cur_c = comp ? cur_c->left : cur_c->right;
			}
			iterator	it = iterator(cur);
			if (comp) {
				if (it == iterator(_leftmost()))
					return pair<iterator, bool>(_insert(cur_c, cur, value), true);
				else
					--it;
			}
			if (m_compare(KeyOfValue()(it.m_node->value), KeyOfValue()(value)))
				return pair<iterator, bool>(_insert(cur_c, cur, value), true);
			return pair<iterator, bool>(it, false);
		}

		iterator	insert_unique(iterator position, const Value& value) {
			// 반복자가 최소값이고 삽입할 값이 더 작은 값일 때 최적화
			if (position.m_node == _leftmost()) {
				if (size() > 0 && 
				m_compare(KeyOfValue()(value), KeyOfValue()(position.m_node->value)))
					return _insert(position.m_node, position.m_node, value);
				// first argument just needs to be non-null 
				else
					return insert_unique(value).first;
				// 반복자가 end() 이고 최대값 보다 value값이 클 때 최적화
			} else if (position == end()) { // end()
				if (m_compare(KeyOfValue()(_rightmost()->value), KeyOfValue()(value)))
					return _insert(0, _rightmost(), value);
				else
					return insert_unique(value).first;
				// 주어진 반복자의 한 단계 작은 값의 반복자의 값으로 비교를 하는데 
			} else {
				iterator before = position;
				--before;
				// value가 이전 값 보다  크고 입력 값 보다 작을 때 최적화, 곧 중복 값이 아닐 때
				if (m_compare(KeyOfValue()(before.m_node->value), KeyOfValue()(value)) 
					&& m_compare(KeyOfValue()(value), KeyOfValue()(position.m_node->value))) {
				if (before.m_node->right == 0)
					return _insert(0, before.m_node, value); 
				else
					return _insert(position.m_node, position.m_node, value);
				// first argument just needs to be non-null 
				} else
				// 최적화가 안될 때
				return insert_unique(value).first;
			}
		}

		// pair값을 리턴하는 함수를 사용하여 값을(반복자를 역참조하여) 넣음
		template<class InputIterator>
		void	insert_unique(InputIterator first, InputIterator last) {
			for (; first != last; ++first)
				insert_unique(*first);
		}

		void	erase(iterator position) {
			Link_type y = _rb_erase_rebalance(position.m_node);
			_destroy_node(y);
			--m_cnt;
		}

		size_type erase(const key_type& x) {
			iterator	it = find(x);
			if (it.m_node == m_header)
				return 0;
			erase(it);
			return 1;
		}

  		void erase(iterator first, iterator last) {
			if (first == begin() && last == end())
				clear();
			else
				while (first != last)
					erase(first++);
		}
  		
		void erase(const key_type* first, const key_type* last) {
			if (first == begin() && last == end())
				clear();
			else
				while (first != last)
					erase(first++);
		}

	protected:
		Link_type		m_header;
		size_type		m_cnt;
		Compare			m_compare;
		Node_allocator	m_node_alloc;
		allocator_type	m_value_alloc;
	};

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline bool	operator==(const Tree<Key, Value, KeyOfValue, Compare, Allocator>& x,
							const Tree<Key, Value, KeyOfValue, Compare, Allocator>& y)
	{ return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin()); }

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline bool	operator!=(const Tree<Key, Value, KeyOfValue, Compare, Allocator>& x,
							const Tree<Key, Value, KeyOfValue, Compare, Allocator>& y)
	{ return !(x == y); }

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline bool	operator<(const Tree<Key, Value, KeyOfValue, Compare, Allocator>& x,
							const Tree<Key, Value, KeyOfValue, Compare, Allocator>& y)
	{ return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()); }
	template <typename Key, typename Value, typename KeyOfValue, typename  Compare, typename Allocator>
	inline bool	operator>(const Tree<Key, Value, KeyOfValue, Compare, Allocator>& x,
							const Tree<Key, Value, KeyOfValue, Compare, Allocator>& y)
	{ return y < x; }
	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline bool	operator<=(const Tree<Key, Value, KeyOfValue, Compare, Allocator>& x,
							const Tree<Key, Value, KeyOfValue, Compare, Allocator>& y)
	{ return !(y < x); }
	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline bool	operator>=(const Tree<Key, Value, KeyOfValue, Compare, Allocator>& x,
							const Tree<Key, Value, KeyOfValue, Compare, Allocator>& y)
	{ return !(x < y); }
	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator>
	inline void	swap(Tree< Key, Value, KeyOfValue, Compare, Allocator>& x,
						Tree< Key, Value, KeyOfValue, Compare, Allocator>& y)
	{ x.swap(y); }

}
