/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:24:39 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/03 19:00:41 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl    harl;

	if (ac != 2)
		{std::cout << "usage : ./ex06 <level>\n"; return 1;}
	harl.complain(av[1]);
	return 0;
}
