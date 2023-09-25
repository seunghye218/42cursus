/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:49:10 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/13 14:19:22 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#define CT1_NAME "CT1"
#define CT2_NAME "CT2"

int main()
{
	ClapTrap	ct1(CT1_NAME);
	ClapTrap	ct2(CT2_NAME);

	ct1.attack(CT2_NAME);
	ct2.takeDamage(ct1.getAP());
	ct2.print_status();
	std::cout << std::endl;

	ct2.beRepaired(2);
	ct2.print_status();
	std::cout << std::endl;

	ct2.attack(CT1_NAME);
	ct1.takeDamage(ct2.getAP());
	ct1.print_status();
	std::cout << std::endl;

	return 0;
}
