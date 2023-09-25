/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:51:19 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/13 17:53:27 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal") {std::cout << "WrongAnimal constructor called\n";}

WrongAnimal::WrongAnimal(std::string type) : type(type) {std::cout << "WrongAnimal constructor called\n";}

WrongAnimal&WrongAnimal::operator=(const WrongAnimal& animal)
{
	if (this != &animal)
		type = animal.type;
	return *this;
}

WrongAnimal::WrongAnimal(const WrongAnimal& animal) : type(animal.type)
{
	std::cout << "WrongAnimal Copy constructor called\n";
	*this = animal;
}

WrongAnimal::~WrongAnimal() {std::cout << "WrongAnimal Destructor called\n";}
