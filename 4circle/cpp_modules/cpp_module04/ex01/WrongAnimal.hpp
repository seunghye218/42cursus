/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:50:38 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/13 18:08:36 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal(void);
		WrongAnimal(std::string);
		WrongAnimal(const WrongAnimal&);
		WrongAnimal&operator=(const WrongAnimal&);
		~WrongAnimal();

		void	makeSound(void) const {std::cout << "**WrongAnimal sound**\n";}
		const std::string&	getType(void) const {return type;}
		void		setType(std::string type) {this->type = type;}
};
