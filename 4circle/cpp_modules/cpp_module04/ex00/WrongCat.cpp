/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:54:21 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/13 17:54:59 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {std::cout << "WrongCat constructor called\n";}

WrongCat&WrongCat::operator=(const WrongCat& cat)
{
	if (this != &cat)
		type = cat.type;
	return *this;
}

WrongCat::WrongCat(const WrongCat& cat) : WrongAnimal(cat.type)
{
	std::cout << "WrongCat Copy constructor called\n";
	*this = cat;
}

WrongCat::~WrongCat() {std::cout << "WrongCat Destructor called\n";}
