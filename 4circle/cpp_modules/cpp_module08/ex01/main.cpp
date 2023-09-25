/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:49:24 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/26 14:54:50 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

std::vector<int> randomVector(unsigned int size)
{
	std::vector<int>	v(size, 0);
	
	srand(time(0));
	for (std::vector<int>::iterator i = v.begin(), end = v.end(); i != end; ++i)
		*i = rand() * (rand() % 2 ? 1 : -1);
	return v;
}

int	main()
{
	std::vector<int>	v = randomVector(100000);
	std::cout << "\n< Test Pdf >\n\n";
	{
		Span sp = Span(5);
		sp.addNumber(6); 
		sp.addNumber(3); 
		sp.addNumber(17); 
		sp.addNumber(9); 
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl; 
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "\n< Test 5 Size >\n\n";
	{
		Span	s(5);

		s.fill(v.begin(), v.begin() + 5);
		s.print();
		std::cout << "shortestSpan: " << s.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << s.longestSpan() << std::endl;
	}
	std::cout << "\n< Test 10000 Size >\n\n";
	{
		Span	s(10000);

		s.fill(v.begin(), v.begin() + 10000);
		std::cout << "shortestSpan: " << s.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << s.longestSpan() << std::endl;
	}
	std::cout << "\n< Test 100000 Size >\n\n";
	{
		Span	s(100000);

		s.fill(v.begin(), v.end());
		std::cout << "shortestSpan: " << s.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << s.longestSpan() << std::endl;
	}
	return 0;
}
