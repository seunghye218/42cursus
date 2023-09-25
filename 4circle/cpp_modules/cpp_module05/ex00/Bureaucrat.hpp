/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:35:35 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/19 18:29:31 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>

using std::string;

class	Bureaucrat
{
	private:
		const string	name;
		int				grade;
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

		static void		checkGrade(int n)
		{
			if (n < 1)
        		throw Bureaucrat::GradeTooHighException();
			else if (n > 150)
        		throw Bureaucrat::GradeTooLowException();
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
