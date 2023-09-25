/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:28:24 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/13 20:56:29 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat constructor called\n";
	brain = new Brain;
}

Cat&Cat::operator=(const Cat& cat)
{
	if (this != &cat)
	{
		type = cat.type;
		for (int i = 0;i < 100; ++i)
			brain->setIdea(i, cat.brain->getIdea(i));
	}
	return *this;
}

Cat::Cat(const Cat& cat) : Animal(cat.type)
{
	std::cout << "Cat Copy constructor called\n";
	*this = cat;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called\n";
	delete brain;
}
