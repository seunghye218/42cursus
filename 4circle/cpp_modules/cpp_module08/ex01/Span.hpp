/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:57:56 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/26 14:28:42 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <iostream>
#include <stdexcept>

class	Span
{
	private:
		std::vector<int>	C;
	public:
		Span(void);
		Span(unsigned int);
		Span(const Span&);
		~Span(void);
		Span&operator=(const Span&);

		void    addNumber(int);
		unsigned int		shortestSpan(void);
		unsigned int		longestSpan(void);
		void	fill(std::vector<int>::iterator, std::vector<int>::iterator);
		void    print(void);
};
