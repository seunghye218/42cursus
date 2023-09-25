/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:50:36 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/19 18:51:10 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void) : name("default"), grade(150) {}

Bureaucrat::Bureaucrat(string name, int n) : name(name)
{
	checkGrade(n);
	grade = n;
}

Bureaucrat::Bureaucrat(const Bureaucrat& b) {*this = b;}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b)
{
	if (this != &b)
	{
		name = b.name;
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

void	Bureaucrat::signForm(Form& f)
{
	try
		{f.beSigned(*this);}
	catch (std::exception &e)
	{
		std::cout << getName() << " couldn't sign "
				<< f.getName() << " because "
				<< e.what() <<".\n";
		return ;
	}
	std::cout << getName() << " signed " << f.getName() << std::endl;
}

void	Bureaucrat::executeForm(Form const & f)
{
	try
	{
		f.execute(*this);
	}
	catch (std::exception &e)
	{
		std::cout << getName() << " couldn't excute "
				<< f.getName() << " because "
				<< e.what() <<".\n";
		return ;
	}
	std::cout << getName() << " executed " << f.getName() << std::endl;
}
