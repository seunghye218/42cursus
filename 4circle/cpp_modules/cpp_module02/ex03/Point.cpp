/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:38:36 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/06 19:30:58 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void) : x(), y() {}

Point::Point(const float f1, const float f2) : x(f1), y(f2) {}

Point::~Point(void) {}

Point&  Point::operator=(const Point& p)
{
	const_cast<Fixed&>(x) = p.x;
	const_cast<Fixed&>(y) = p.y;
	return *this;
}

Point::Point(const Point& p)
{
	*this = p;
}

const Fixed	Point::getX(void)
{
	return x;
}

const Fixed	Point::getY(void)
{
	return y;
}
