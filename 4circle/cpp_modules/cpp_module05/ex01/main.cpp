/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:37:46 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/19 18:35:39 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "\n< Test Constructor >\n\n";
	{
		try
		{
			Form f1("f1", 0, 10);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			Form f1("f1", 2, 151);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n< Test Low Grade>\n\n";
	{
		Bureaucrat b("bureaucrat", 20);
		Form f("form", 10, 5);

		std::cout << b;
		std::cout << f;
		b.signForm(f);
	}
	std::cout << "\n< Test Already Signed >\n\n";
	{
		Bureaucrat b("bureaucrat", 3);
		Form f("form", 10, 5);

		std::cout << b;
		std::cout << f;
		b.signForm(f);
		std::cout << f;
		b.signForm(f);
	}
	std::cout << std::endl;
	return 0;
}
