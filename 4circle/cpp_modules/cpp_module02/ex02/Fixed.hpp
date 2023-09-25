/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:41:52 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/11 15:33:01 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	Fixed
{
	private:
		int					fixedVal;
		static const int	fractBit = 8;

	public:
		int		getRawBits(void) const;
		void	setRawBits(int const);

		Fixed(void);
		Fixed(const Fixed&);
		~Fixed(void);
		Fixed&	operator=(const Fixed&);

		float	toFloat(void) const;
		int		toInt(void) const;
		Fixed(const int);
		Fixed(const float);

		bool	operator>(const Fixed&);
		bool	operator>=(const Fixed&);
		bool	operator<(const Fixed&);
		bool	operator<=(const Fixed&);
		bool	operator==(const Fixed&);
		bool	operator!=(const Fixed&);
		Fixed	operator+(const Fixed&) const;
		Fixed	operator+(void) const;
		Fixed	operator-(const Fixed&) const;
		Fixed	operator-(void) const;
		Fixed	operator*(const Fixed&) const;
		Fixed	operator/(const Fixed&) const;
		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);
		static Fixed&		min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&		max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream&	operator<<(std::ostream& os, const Fixed&);
