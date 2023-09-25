/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:35:35 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/19 18:50:45 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>

using std::string;

class	Form;

class	Bureaucrat
{
	private:
		string	name;
		int		grade;
	public:
		Bureaucrat(void);
		Bureaucrat(string name, int n = 150);
		Bureaucrat(const Bureaucrat&);
		Bureaucrat& operator=(const Bureaucrat&);
		~Bureaucrat(void);

		const string&	getName(void) const {return name;}
		int				getGrade(void) const {return grade;}
		void			incrementGrade(void);
		void			decrementGrade(void);
		void			signForm(Form&);
		void			executeForm(Form const &);


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

};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);
