/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:35:51 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/24 13:06:39 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base * generate(void)
{
	srand(time(0));
	switch ((rand() % 3))
	{
		case 0 : return new A();
		case 1 : return new B();
	}
	return new C();
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A Class\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B Class\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C Class\n";
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A Class\n";
	}
	catch (std::bad_cast)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "B Class\n";
		}
		catch (std::bad_cast)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "C Class\n";
			}
			catch (std::bad_cast)
			{
				std::cout << "Invalid Class\n";
			}
		}
	}
}

int main(void)
{
    Base    *p = generate();

    identify(p);
    identify(*p);

    delete p;

    return 0;
}
