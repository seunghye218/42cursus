/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:28:24 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/13 16:53:10 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {std::cout << "Cat constructor called\n";}

Cat&Cat::operator=(const Cat& cat)
{
	if (this != &cat)
		type = cat.type;
	return *this;
}

Cat::Cat(const Cat& cat) : Animal(cat.type)
{
	std::cout << "Cat Copy constructor called\n";
	*this = cat;
}

Cat::~Cat() {std::cout << "Cat Destructor called\n";}
