/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:35:24 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/24 12:40:51 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
#include <iomanip>

Convert::Convert(void) {}

Convert::Convert(char* str) : s(str)
{
	char	*p;

	d = std::strtod(str, &p);
	if (s.length() == 1 && !std::isdigit(s[0]))
		d = static_cast<char>(s[0]);
	else if ((*str == '\0' || (*p && !(*p == 'f' && *(p + 1) == '\0'))))
		throw std::invalid_argument(s);
	std::cout << std::setprecision(1) << std::fixed;
}

Convert::Convert(const Convert& C) {*this = C;}

Convert::~Convert(void) {}

Convert&Convert::operator=(const Convert& C)
{
	if (this != &C)
	{
		s = C.s;
		d = C.d;
	}
	return *this;
}

void	Convert::displayChar(void)
{
		char	c = static_cast<char>(d);

		std::cout << "char: ";
		if (static_cast<double>(c) != d)
			std::cout << "impossible" << std::endl;
		else if (!std::isprint(c))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout<<  '\'' << c << "'\n";
}

void		Convert::displayInt(void)
{
		int	i = static_cast<int>(d);

		std::cout << "int: ";
		if (isnan(d) ||
			static_cast<double>(i) != d ||
			(d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()))
			std::cout << "impossible" << std::endl;
		else
			std::cout << i << std::endl;
}

void	Convert::displayFloat(void)
{
	float	f = static_cast<float>(d);

	std::cout << "float: ";
	if (isnan(d))
		std::cout << "nanf\n";
	else if (static_cast<double>(f) != d &&
			((d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max()) ||
			((d < 0 && d > -std::numeric_limits<float>::min()) || (d > 0 && d < std::numeric_limits<float>::min()))))
		std::cout << "impossible" << std::endl;
	else
		std::cout << f << "f\n";
}

void	Convert::displayDouble(void)
{
	std::cout << "double: " << d << std::endl;
}
