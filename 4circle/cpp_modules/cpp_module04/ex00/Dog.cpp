/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:20:22 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/13 16:53:06 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {std::cout << "Dog constructor called\n";}

Dog&Dog::operator=(const Dog& dog)
{
	if (this != &dog)
		type = dog.type;
	return *this;
}

Dog::Dog(const Dog& dog) : Animal(dog.type)
{
	std::cout << "Dog Copy constructor called\n";
	*this = dog;
}

Dog::~Dog() {std::cout << "Dog Destructor called\n";}
