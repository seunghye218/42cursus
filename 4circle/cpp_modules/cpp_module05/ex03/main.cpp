/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:37:46 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/19 19:12:00 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Bureaucrat	b1("b1", 1);
	Bureaucrat	b150("b150", 150);
	Intern  	someRandomIntern;
	Form*   	form;

	std::cout << "\n < Test Failed Case> \n\n";

	if ((form = someRandomIntern.makeForm("blabla", "target")))
	{
		b1.signForm(*form);
		b1.executeForm(*form);
		delete form;
	}
	
	std::cout << "\n < Test shrubbery> \n\n";

	if ((form = someRandomIntern.makeForm("shrubbery creation", "target1")))
	{
		b150.signForm(*form);
		b150.executeForm(*form);
		b1.signForm(*form);
		b1.executeForm(*form);
		delete form;
	}

	std::cout << "\n < Test robotomy> \n\n";

	if ((form = someRandomIntern.makeForm("robotomy request", "target2")))
	{
		b1.signForm(*form);
		b1.executeForm(*form);
		delete form;
	}

	std::cout << "\n < Test presidential> \n\n";

	if ((form = someRandomIntern.makeForm("presidential pardon", "target3")))
	{
		b150.signForm(*form);
		b1.signForm(*form);
		b1.executeForm(*form);
		delete form;
	}

	std::cout << std::endl;
	return 0;
}
