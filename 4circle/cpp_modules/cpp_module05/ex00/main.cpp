/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:37:46 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/19 18:32:34 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "\n< Test Constructor >\n\n";
	{
		try
		{
			Bureaucrat b1("b1", 0);
			std::cout << "after throw\n";
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			Bureaucrat b1("b2", 151);
			std::cout << "after throw\n";
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n< Test (in/de)crementGrade >\n\n";
	{
		try
		{
			Bureaucrat b1("b1", 1);
			b1.incrementGrade();
			std::cout << "after throw\n";
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			Bureaucrat b1("b2", 150);
			b1.decrementGrade();
			std::cout << "after throw\n";
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n< Test >\n\n";
	{
		try
		{
			Bureaucrat b1("b", 5);
			std::cout << b1;
			b1.incrementGrade();
			std::cout << b1;
			b1.decrementGrade();
			std::cout << b1;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	return 0;
}
