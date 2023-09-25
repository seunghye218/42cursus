/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:20:03 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/13 21:08:26 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	Animal
{
	protected:
		std::string	type;
	public:
		Animal(void);
		Animal(std::string);
		Animal(const Animal&);
		Animal&operator=(const Animal&);
		virtual	~Animal();

		virtual void	makeSound(void) const {std::cout << "**Animal sound**\n";}
		const std::string&	getType(void) const {return type;}
};
