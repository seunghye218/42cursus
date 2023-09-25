/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:36:49 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/20 20:44:23 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		{std::cout << "usage: ./convert [string]\n"; return 1;}
	try
	{
		Convert	C(av[1]);

		C.displayChar();
		C.displayInt();
		C.displayFloat();
		C.displayDouble();
	}
	catch (std::invalid_argument &ia)
	{
		std::cout << "Invalid argument : " << ia.what() << std::endl;
	}
	return 0;
}