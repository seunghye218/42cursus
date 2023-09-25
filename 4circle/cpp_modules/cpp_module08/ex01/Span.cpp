/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:57:27 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/26 14:54:43 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>

Span::Span(void) : C(0, 0) {}

Span::Span(unsigned int N) : C(0, 0)
{
	C.reserve(N);
}

Span::Span(const Span& S) {*this = S;}

Span&Span::operator=(const Span& S)
{
	if (this != &S)
	{
		C.reserve(S.C.size());
		C = S.C;
	}
	return *this;
}

Span::~Span(void) {}

void    Span::addNumber(int n)
{
	if (C.size() == C.capacity())
		throw std::out_of_range("out_of_range");
	C.push_back(n);
}

unsigned int	f(int n)
{
	return (std::abs(n));
}

unsigned int	Span::shortestSpan(void)
{
	std::vector<long>	r(C.size(), 0);

	if (C.size() < 2)
		return 0;
	std::adjacent_difference(C.begin(), C.end(), r.begin());
	*r.begin() = *(r.begin() + 1);
	std::transform(r.begin(), r.end(),r.begin(), f);
	return *(std::min_element(r.begin(), r.end()));
}

unsigned int	Span::longestSpan(void)
{
	if (C.size() < 2)
		return 0;
	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> p = std::minmax_element(C.begin(), C.end());
	return *p.second - *p.first;
}

void	Span::fill(std::vector<int>::iterator it, std::vector<int>::iterator ite)
{
	if ((std::distance(it, ite)) <= static_cast<long>(C.capacity() + C.size()))
		for (;it != ite; ++it)
			C.push_back(*it);
}

void    Span::print(void)
{
	for (std::vector<int>::iterator i = C.begin(); i != C.end(); ++i)
		std::cout << *i << std::endl;
}
