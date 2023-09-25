/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:14:44 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/19 17:24:39 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class	Intern
{
	public:
		Intern(void);
		Intern(const Intern&);;
		~Intern(void);
		Intern&operator=(const Intern&);
		Form*	makeForm(string, string);
};
