/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:18:40 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/19 15:13:44 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class	Form
{
	private:
		const string	name;
		const string	target;
		bool			isSigned;
		const int		signGrade;
		const int		execGrade;
	public:
		Form(void);
		Form(string, string, int, int);
		Form(const Form&);
		Form& operator=(const Form&);
		virtual ~Form(void);

		const string&	getName(void) const {return name;}
		const string&	getTarget(void) const {return target;}
		bool			getIsSigned(void) const {return isSigned;}
		int				getSignGrade(void) const {return signGrade;}
		int				getExecGrade(void) const {return execGrade;}
		void			beSigned(const Bureaucrat&);
		virtual void	execute(Bureaucrat const & executor) const = 0;

		void	checkGrade(int n)
		{
			if (n < 1)
				throw GradeTooHighException();
			else if (n > 150)
				throw GradeTooLowException();
		}

		void	checkExec(const Bureaucrat& b) const
		{
			if (!isSigned)
				throw NotSigned();
			else if (b.getGrade() > execGrade)
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

		class	NotSigned : public std::exception
		{
			public:
				const char* what(void) const throw()
					{return "NotSigned";}
		};

};

std::ostream& operator<<(std::ostream&, const Form&);
