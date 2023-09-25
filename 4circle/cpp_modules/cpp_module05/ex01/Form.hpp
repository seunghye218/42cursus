/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:18:40 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/19 14:02:54 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class	Form
{
	private:
		const string	name;
		bool			isSigned;
		const int		signGrade;
		const int		execGrade;
	public:
		Form(void);
		Form(string, int, int);
		Form(const Form&);
		Form& operator=(const Form&);
		~Form(void);

		const string&	getName(void) const {return name;}
		bool			getIsSigned(void) const {return isSigned;}
		int				getSignGrade(void) const {return signGrade;}
		int				getExecGrade(void) const {return execGrade;}

		void	checkGrade(int n)
		{
			if (n < 1)
				throw GradeTooHighException();
			else if (n > 150)
				throw GradeTooLowException();
		}

		class	GradeTooHighException : public std::exception
		{
			public:
				const char* what(void) const throw()
					{return "GradeTooHigh";}
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				const char* what(void) const throw()
					{return "GradeTooLow";}
		};

		class	AlreadySigned : public std::exception
		{
			public:
				const char* what(void) const throw()
					{return "AleadySigned";}
		};

		void	beSigned(const Bureaucrat&);
};

std::ostream& operator<<(std::ostream&, const Form&);
