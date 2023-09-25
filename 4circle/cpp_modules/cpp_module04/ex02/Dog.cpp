/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:20:22 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/13 20:56:32 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog constructor called\n";
	brain = new Brain;
}

Dog&Dog::operator=(const Dog& dog)
{
	if (this != &dog)
	{
		type = dog.type;
		for (int i = 0;i < 100; ++i)
			brain->setIdea(i, dog.brain->getIdea(i));
	}
	return *this;
}

Dog::Dog(const Dog& dog) : Animal(dog.type)
{
	std::cout << "Dog Copy constructor called\n";
	*this = dog;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called\n";
	delete brain;
}
