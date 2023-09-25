/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:50:36 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/19 18:33:24 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("default"), grade(150) {}

Bureaucrat::Bureaucrat(string name, int n) : name(name)
{
	checkGrade(n);
	grade = n;
}

Bureaucrat::Bureaucrat(const Bureaucrat& b) : name(b.name), grade(b.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b)
{
	if (this != &b)
	{
		const_cast<string&>(name) = b.name;
		grade = b.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat(void) {}

void    Bureaucrat::incrementGrade(void)
{
	checkGrade(grade - 1);
	--grade;
}

void	Bureaucrat::decrementGrade(void)
{
	checkGrade(grade + 1);
	++grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &b)
{
	std::cout << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
	return os;
}
