/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:22:56 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/12 16:01:06 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap()
{
	std::cout << name << " DiamondTrap constructor called\n";
	hitPoint = trapStat::D_HP;
	energyPoint = trapStat::D_EP;
	attackPoint = trapStat::D_AP;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << name << " DiamondTrap destructor called\n";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), name(name)
{
	std::cout << name << " DiamondTrap constructor called\n";
	hitPoint = trapStat::D_HP;
	energyPoint = trapStat::D_EP;
	attackPoint = trapStat::D_AP;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondTrap)
{
	std::cout << name << " DiamondTrap Copy constructor called\n";
	hitPoint = diamondTrap.hitPoint;
	energyPoint = diamondTrap.energyPoint;
	attackPoint = diamondTrap.attackPoint;
	return *this;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap)
{
	*this = diamondTrap;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	if (!hitPoint)
		{std::cout << "DiamondTrap " << name << " is already dead\n"; return;}
	std::cout << "DiamondTrap " << name << " taked " << amount << " points of damage\n";
	if (hitPoint > amount)
		hitPoint -= amount;
	else
		hitPoint = 0;
}

void DiamondTrap::beRepaired(unsigned int amount)
{
	if (!hitPoint)
		{std::cout << "DiamondTrap " << name << " is already dead\n"; return;}
	if (energyPoint)
	{
		std::cout << "DiamondTrap " << name << " repaired " << amount << " points\n";
		--energyPoint;
		hitPoint += amount;
	}
	else
		std::cout << "DiamondTrap " << name << " has not enough energy\n";
}

void	DiamondTrap::whoAmI(void)
{
	if (!hitPoint)
		return ;
	std::cout << "whoAmI : " << name << ", " << ClapTrap::name << std::endl;
}
