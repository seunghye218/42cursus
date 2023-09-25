/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:49:10 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/13 13:59:16 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#define CT_NAME "CT"
#define ST_NAME "ST"
#define FT_NAME "FT"
#define DT_NAME "DT"

int main()
{
	ClapTrap	ct(CT_NAME);
	ScavTrap	st(ST_NAME);
	FragTrap	ft(FT_NAME);
	DiamondTrap	dt(DT_NAME);

	std::cout << std::endl;

	st.attack(FT_NAME);
	dt.takeDamage(st.getAP());
	dt.print_status();
	std::cout << std::endl;

	ct.attack(FT_NAME);
	dt.takeDamage(ct.getAP());
	dt.print_status();
	std::cout << std::endl;

	ft.attack(FT_NAME);
	dt.takeDamage(ft.getAP());
	dt.print_status();
	std::cout << std::endl;

	dt.attack(CT_NAME);
	ct.takeDamage(dt.getAP());
	ct.print_status();
	std::cout << std::endl;

	ct.beRepaired(12);
	std::cout << std::endl;

	dt.beRepaired(30);
	dt.print_status();
	std::cout << std::endl;

	dt.attack(ST_NAME);
	st.takeDamage(ft.getAP());
	st.print_status();
	std::cout << std::endl;

	st.guardGate();
	std::cout << std::endl;

	ft.highFivesGuys();
	std::cout << std::endl;

	dt.guardGate();
	dt.highFivesGuys();
	dt.whoAmI();
	std::cout << std::endl;

	return 0;
}
