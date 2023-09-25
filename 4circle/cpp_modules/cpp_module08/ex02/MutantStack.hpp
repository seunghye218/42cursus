/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:18:52 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/26 13:35:43 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iterator>
#include <stack>

template <typename T>
class	MutantStack : public std::stack<T>
{
	public:
		MutantStack(void) {}
		MutantStack&operator=(const MutantStack& M)
		{
			if (this != &M)
				std::stack<T>::operator=(M);
			return *this;
		}
		MutantStack(const MutantStack& M) {*this = M;}
		~MutantStack(void) {}

		using	std::stack<int>::container_type;

		typedef container_type::iterator iterator;
		typedef container_type::reverse_iterator reverse_iterator;

		container_type::iterator begin(void) {return this->c.begin();}
		container_type::iterator end(void) {return this->c.end();}
		container_type::reverse_iterator rbegin(void) {return this->c.rbegin();}
		container_type::reverse_iterator rend(void) {return this->c.rend();}
};
