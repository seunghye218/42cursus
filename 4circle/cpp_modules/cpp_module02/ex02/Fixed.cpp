/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:54:15 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/11 15:33:02 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : fixedVal(0) {}

Fixed::~Fixed(void) {}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	fixedVal = fixed.fixedVal;
	return *this;
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
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
	fixedVal = n << 8;
}

Fixed::Fixed(const float f)
{
	fixedVal = roundf(f * 256);
}

float	Fixed::toFloat(void) const
{
	return static_cast<float>(fixedVal) / 256;
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

bool	Fixed::operator>(const Fixed& fixed)
{
	return fixedVal > fixed.fixedVal;
}

bool	Fixed::operator>=(const Fixed& fixed)
{
	return fixedVal >= fixed.fixedVal;
}

bool	Fixed::operator<(const Fixed& fixed)
{
	return fixedVal < fixed.fixedVal;
}

bool	Fixed::operator<=(const Fixed& fixed)
{
	return fixedVal <= fixed.fixedVal;
}

bool	Fixed::operator==(const Fixed& fixed)
{
	return fixedVal == fixed.fixedVal;
}

bool	Fixed::operator!=(const Fixed& fixed)
{
	return fixedVal != fixed.fixedVal;
}

Fixed	Fixed::operator+(const Fixed& fixed) const
{
	Fixed	temp;
	temp.setRawBits(fixedVal + fixed.fixedVal);
	return temp;
}

Fixed	Fixed::operator+(void) const
{
	Fixed	temp;
	temp.setRawBits(fixedVal);
	return temp;
}

Fixed	Fixed::operator-(const Fixed& fixed) const
{
	Fixed	temp;
	temp.setRawBits(fixedVal - fixed.fixedVal);
	return temp;
}

Fixed	Fixed::operator-(void) const
{
	Fixed	temp;
	temp.setRawBits(-fixedVal);
	return temp;
}

Fixed	Fixed::operator*(const Fixed& fixed) const
{
	return Fixed(toFloat() * fixed.toFloat());
}

Fixed	Fixed::operator/(const Fixed& fixed) const
{
	if (!fixed.toFloat())
		{std::cout << "Divide by zero\n"; exit(1);}
	return Fixed(toFloat() / fixed.toFloat());
}

Fixed&	Fixed::operator++(void)
{
	++fixedVal;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed temp;

	temp.setRawBits(fixedVal);
	++fixedVal;
	return temp;
}

Fixed&	Fixed::operator--(void)
{
	--fixedVal;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed temp;

	temp.setRawBits(fixedVal);
	--fixedVal;
	return temp;
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return a.fixedVal <= b.fixedVal ? a : b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return a.fixedVal <= b.fixedVal ? a : b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return a.fixedVal >= b.fixedVal ? a : b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return a.fixedVal >= b.fixedVal ? a : b;
}
