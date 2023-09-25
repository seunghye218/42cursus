/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:21:25 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/26 13:46:25 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iterator>
#include <vector>
#include <deque>
#include <list>
#include <iostream>

int	main()
{
	int	arr[10] = {0,1,2,3,4,5,6,7,8,9};
	std::cout << "\n < Test Vector >\n\n";
	{
		std::vector<int>	vt(arr, arr + sizeof(arr));

		std::vector<int>::iterator	i = easyfind(vt, 3);
		std::cout << std::distance(vt.begin(), i) << std::endl;
		try
		{
			i = easyfind(vt, 10);
			std::cout << std::distance(vt.begin(), i) << std::endl;
		} catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n < Test Deque >\n\n";
	{		
		std::deque<int> dq;
		for (int i = 0; i < 10; ++i)
			dq.push_back(arr[i]);

		std::deque<int>::iterator	i = easyfind(dq, 3);
		std::cout << std::distance(dq.begin(), i) << std::endl;
		try
		{
			i = easyfind(dq, 10);
			std::cout << *i << std::endl;
		} catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n < Test List >\n\n";
	{
		std::list<int> ls;
		ls.assign(arr, arr + sizeof(arr));

		std::list<int>::iterator	i;

		i = easyfind(ls, 3);
		std::cout << std::distance(ls.begin(), i) << std::endl;
		try
		{
			i = easyfind(ls, 10);
			std::cout << std::distance(ls.begin(), i) << std::endl;
		} catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}