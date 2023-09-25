/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:17:43 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/19 16:06:52 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyCreationForm", "default",145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(string target) : Form("ShrubberyCreationForm", target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& s) : Form(s.getName(), s.getTarget(), 145, 137) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm&) {return *this;}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	checkExec(executor);
	
	std::ofstream	of;

	try
		{of.open((getTarget() + "_shrubbery"));}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	of << 
			"   oxoxoo    ooxoo\n"
			"  ooxoxo oo  oxoxooo\n"
			" oooo xxoxoo ooo ooox\n"
			" oxo o oxoxo  xoxxoxo\n"
			"  oxo xooxoooo o ooo\n"
			"    ooo\\oo\\  /o/o\n"
			"        \\  \\/ /\n"
			"         |   /\n"
			"         |  |\n"
			"         | D|\n"
			"         |  |\n"
			"         |  |\n"
			"  ______/____\\____\n";
	of.close();
}
