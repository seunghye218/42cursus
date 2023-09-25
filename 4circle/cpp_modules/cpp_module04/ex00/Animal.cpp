/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:13:41 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/13 16:53:13 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Animal") {std::cout << "Animal constructor called\n";}

Animal::Animal(std::string type) : type(type) {std::cout << "Animal constructor called\n";}

Animal&Animal::operator=(const Animal& animal)
{
	if (this != &animal)
		type = animal.type;
	return *this;
}

Animal::Animal(const Animal& animal) : type(animal.type)
{
	std::cout << "Animal Copy constructor called\n";
	*this = animal;
}

Animal::~Animal() {std::cout << "Animal Destructor called\n";}
