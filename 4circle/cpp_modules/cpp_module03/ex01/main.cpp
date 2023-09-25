/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:49:10 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/13 14:27:10 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#define CT_NAME "CT"
#define ST_NAME "ST"

int main()
{
	ClapTrap	ct(CT_NAME);
	ScavTrap	st(ST_NAME);

	std::cout << std::endl;

	ct.beRepaired(12);
	ct.print_status();
	std::cout << std::endl;

	st.attack(CT_NAME);
	ct.takeDamage(st.getAP());
	ct.print_status();
	std::cout << std::endl;

	st.attack(CT_NAME);
	ct.takeDamage(st.getAP());
	ct.print_status();
	std::cout << std::endl;

	ct.beRepaired(12);
	ct.print_status();
	std::cout << std::endl;

	st.guardGate();
	std::cout << std::endl;

	return 0;
}
