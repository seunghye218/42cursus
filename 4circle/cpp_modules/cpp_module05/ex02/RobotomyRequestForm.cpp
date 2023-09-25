/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:36:25 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/19 18:58:54 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <stdlib.h>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(void) : Form("RobotomyRequestForm", "default", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(string target) : Form("RobotomyRequestForm", target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& s) : Form(s) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm&) {return *this;}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	checkExec(executor);

	srand(time(0));
	if (rand() % 2)
	{
		std::cout << "* drilling noises *\n"
				<< getTarget() << " has been robotomized\n";
	}
	else
		std::cout << getTarget() << " has failed robotomized\n";
}
