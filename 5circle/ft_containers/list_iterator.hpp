/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:25:34 by seunghye          #+#    #+#             */
/*   Updated: 2023/02/02 15:14:46 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

template <typename T>
struct  list_node
{
	T   		value;
	list_node*	next;
};

// template <typename T, typename Ref, typname Ptr>
template <typename T>
class  list_iterator
{
private:
	struct list_node<T>*	node;
public:
	// typedef forward_iterator_tag							iterator_category;
	// typedef ptrdiff_t											difference_type;
	typedef T 												value_type;
	typedef T& 												reference;
	typedef T* 												pointer;
	typedef list_iterator<T>								iterator;
	// typedef list_iterator<T, const Value&, const Value*>	const_iterator;

	list_iterator(struct list_node<T>* n)
	{
		this->n = n;
	}

	reference	operator*() const
	{
		return this->node->value;
	}
	pointer		operator->() const;

	iterator	operator++()
	{
		return list_iterator(this->node->next);
	}
	reference	operator++(int);

	// 양방향의 경우 (ex: deque)
	// reference	operator--(int);
	// reference	operator--();
};

template <typename T>
class ft_lst
{
public:
	typedef	list_iterator<T>	iterator;
	typedef	T					value;
	typedef	T&					reference;
	typedef	T*					pointer;
	
	iterator	begin()
	{
		return m_head;
	}
	iterator	end()
	{
		return m_tail;
	}
	size_t		size()
	{
		return m_size;
	}
	
private:
	iterator	m_head;
	iterator	m_tail;
	size_t		m_size;
};