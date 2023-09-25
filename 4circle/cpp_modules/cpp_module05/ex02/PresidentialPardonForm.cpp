/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:38:29 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/19 18:58:07 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("PresidentialPardonForm", "default", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(string target) : Form("PresidentialPardonForm", target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& s) : Form(s) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm&) {return *this;}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	checkExec(executor);

	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox.\n";
}
