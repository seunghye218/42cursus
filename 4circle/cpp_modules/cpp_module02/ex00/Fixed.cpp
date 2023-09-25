/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:54:15 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/11 14:25:23 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : fixedVal(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &fixed) : fixedVal(fixed.fixedVal)
{
	std::cout << "Copy constructor called\n";
	*this = fixed;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called\n";
	setRawBits(fixed.getRawBits());
	return *this;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->fixedVal);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixedVal = raw;
}
