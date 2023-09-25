/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:25:13 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/05 18:18:51 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(string humanName) : name(humanName), weapon(0) {}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack(void)
{
	if (!this->weapon)
		{std::cout << this->name << " attacks with their fists\n"; return;}
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}
