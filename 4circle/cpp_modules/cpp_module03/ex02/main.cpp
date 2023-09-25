/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:49:10 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/13 14:29:30 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#define CT_NAME "CT"
#define ST_NAME "ST"
#define FT_NAME "FT"

int main()
{
	ClapTrap	ct(CT_NAME);
	ScavTrap	st(ST_NAME);
	FragTrap	ft(FT_NAME);

	std::cout << std::endl;

	st.attack(FT_NAME);
	ft.takeDamage(st.getAP());
	ft.print_status();
	std::cout << std::endl;

	ct.attack(FT_NAME);
	ft.takeDamage(ct.getAP());
	ft.print_status();
	std::cout << std::endl;

	ft.attack(CT_NAME);
	ct.takeDamage(ft.getAP());
	ct.print_status();
	std::cout << std::endl;

	ct.beRepaired(12);
	ct.print_status();
	std::cout << std::endl;

	ft.attack(ST_NAME);
	st.takeDamage(ft.getAP());
	st.print_status();
	std::cout << std::endl;

	st.guardGate();
	std::cout << std::endl;

	ft.highFivesGuys();
	std::cout << std::endl;

	return 0;
}
