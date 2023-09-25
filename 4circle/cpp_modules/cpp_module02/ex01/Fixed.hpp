/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:41:52 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/05 16:56:35 by seunghye         ###   ########.fr       */
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
};

std::ostream&	operator<<(std::ostream& os, const Fixed&);
