/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:23:12 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/20 14:23:38 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void)
	: name("default"), isSigned(false), signGrade(150), execGrade(150) {}

Form::Form(string name, int signG, int execG)
	: name(name), isSigned(false), signGrade(signG), execGrade(execG)
{
	checkGrade(signG);
	checkGrade(execG);
}

Form::Form(const Form& b)
	: name(b.name), isSigned(b.isSigned), signGrade(b.signGrade), execGrade(b.execGrade) {}

Form& Form::operator=(const Form& b)
{
	if (this != &b)
	{
		const_cast<string&>(name) = b.name;
		isSigned = b.isSigned;
		const_cast<int&>(signGrade) = b.signGrade;
		const_cast<int&>(execGrade) = b.execGrade;
	}
	return *this;
}

Form::~Form(void) {}

std::ostream& operator<<(std::ostream& os, const Form &f)
{
	std::cout << f.getName() 
			<< ", sign state is " << std::boolalpha << f.getIsSigned() 
			<< ", sign grade is "  << f.getSignGrade()
			<< ", exec grade is " << f.getExecGrade() << ".\n";
	return os;
}

void	Form::beSigned(const Bureaucrat& b)
{
	if (isSigned)
		throw AlreadySigned();
	if (b.getGrade() > signGrade)
		throw GradeTooLowException();
	isSigned = true;
}
