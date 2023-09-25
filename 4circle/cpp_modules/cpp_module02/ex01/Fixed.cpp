/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:54:15 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/11 14:33:14 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(void) : fixedVal(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &fixed)
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
	return (this->fixedVal);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixedVal = raw;
}


Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called\n";
	fixedVal = n << 8;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called\n";
	fixedVal = roundf(f * 256);
}

float	Fixed::toFloat(void) const
{
	return static_cast<float>(this->fixedVal) / 256;
}

int		Fixed::toInt(void) const
{
	return this->fixedVal >> 8;
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	std::cout << fixed.toFloat();
	return os;
}
