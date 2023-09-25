/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:37:46 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/19 17:02:29 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << "\n< Test Fail >\n\n";
	{
		Bureaucrat	b("b", 140);
		ShrubberyCreationForm	scf("SCF1");
		RobotomyRequestForm	rrf("RRF");
		PresidentialPardonForm	ppf("PPF");

		b.signForm(scf);
		b.executeForm(scf);

		b.signForm(rrf);
		b.executeForm(rrf);

		b.signForm(ppf);
		b.executeForm(ppf);

	}
	std::cout << "\n< Test ShrubberyCreationForm >\n\n";
	{
		Bureaucrat	b("b", 1);
		ShrubberyCreationForm	scf("SCF2");

		b.signForm(scf);
		b.executeForm(scf);
	}
	std::cout << "\n< Test RobotomyRequestForm >\n\n";
	{
		Bureaucrat	b("b", 1);
		RobotomyRequestForm	rrf("RRF");

		b.signForm(rrf);
		b.executeForm(rrf);
	}
	std::cout << "\n< Test PresidentialPardonForm >\n\n";
	{
		Bureaucrat	b("b", 1);
		PresidentialPardonForm	ppf("PPF");

		b.signForm(ppf);
		b.executeForm(ppf);
	}
	

	std::cout << std::endl;
	return 0;
}
