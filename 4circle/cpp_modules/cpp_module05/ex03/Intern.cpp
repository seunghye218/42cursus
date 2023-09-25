/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:14:40 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/20 14:32:25 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern&) {}

Intern::~Intern(void) {}

Intern&Intern::operator=(const Intern&) {return *this;}

Form*	Intern::makeForm(string name, string target)
{
	string	formArr[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form	*form;
	int		i;

	for (i = 0; i < 3; ++i)
		if (!name.compare(formArr[i]))
			break;
	try
	{
		switch (i)
		{
			case 0 :
				form = new ShrubberyCreationForm(target); break;
			case 1 :
				form = new RobotomyRequestForm(target); break;
			case 2 :
				form = new PresidentialPardonForm(target); break;
			default:
				form = 0; std::cout << "Invalid Form name\n";
		}
	}
	catch (std::exception &e)
	{
		std::cout  << "makeForm failed : "
				<< e.what() << std::endl;
	}
	if (form)
		std::cout << "Intern creates " << form->getName() << std::endl;
	return form;
}
