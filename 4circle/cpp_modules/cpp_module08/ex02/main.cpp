/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:20:06 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/26 12:34:12 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <iostream>

int main()
{
	std::cout << "\n< Test >\n\n";
	{
		MutantStack<int> mstack;
		mstack.push(5); 
		mstack.push(17);
	
		std::cout << mstack.top() << std::endl; 
		mstack.pop();
		std::cout << mstack.size() << std::endl;

		mstack.push(3); 
		mstack.push(5); 
		mstack.push(737); 
		//[...] 
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin(); 
		MutantStack<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		while (it != ite) 
		{
			std::cout << *it << std::endl;
			++it; 
		}
		std::stack<int> s(mstack); 
	}
	std::cout << "\n< Test List >\n\n";
	{
		std::list<int> mstack;
		mstack.push_back(5); 
		mstack.push_back(17);
	
		std::cout << *mstack.rbegin() << std::endl; 
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;

		mstack.push_back(3); 
		mstack.push_back(5); 
		mstack.push_back(737); 
		//[...] 
		mstack.push_back(0);

		std::list<int>::iterator it = mstack.begin(); 
		std::list<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		while (it != ite) 
		{
			std::cout << *it << std::endl;
			++it; 
		}
		std::list<int> s(mstack); 
	}
	std::cout << "\n< Test reverse_iterator >\n\n";
	{
		MutantStack<int> mstack;

		for (int i = 0; i < 10; ++i)
			mstack.push(i);
		std::copy(mstack.begin(), mstack.end(), std::ostream_iterator<int>(std::cout, "\n"));
		std::cout << std::endl;
		std::copy(mstack.rbegin(), mstack.rend(), std::ostream_iterator<int>(std::cout, "\n"));
	}
	return 0;
}
