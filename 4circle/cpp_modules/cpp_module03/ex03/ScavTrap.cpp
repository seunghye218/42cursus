/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:22:56 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/13 13:47:19 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << name << " ScavTrap constructor called\n";
	hitPoint = trapStat::S_HP;
	energyPoint = trapStat::S_EP;
	attackPoint = trapStat::S_AP;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << name << " ScavTrap destructor called\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << name << " ScavTrap constructor called\n";
	hitPoint = trapStat::S_HP;
	energyPoint = trapStat::S_EP;
	attackPoint = trapStat::S_AP;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavtrap)
{
	std::cout << name << " ScavTrap Copy constructor called\n";
	hitPoint = scavtrap.hitPoint;
	energyPoint = scavtrap.energyPoint;
	attackPoint = scavtrap.attackPoint;
	return *this;
}

ScavTrap::ScavTrap(const ScavTrap& scavtrap)
{
	*this = scavtrap;
}

void	ScavTrap::attack(const std::string &target)
{
	if (!hitPoint)
		{std::cout << "ScavTrap " << name << " is already dead\n"; return;}
	if (energyPoint)
	{
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackPoint << " points of damage!\n";
		--energyPoint;
	}
	else
		std::cout << "ScavTrap " << name << " has not enough energy\n";
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (!hitPoint)
		{std::cout << "ScavTrap " << name << " is already dead\n"; return;}
	std::cout << "ScavTrap " << name << " taked " << amount << " points of damage\n";
	if (hitPoint > amount)
		hitPoint -= amount;
	else
		hitPoint = 0;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (!hitPoint)
		{std::cout << "ScavTrap " << name << " is already dead\n"; return;}
	if (energyPoint)
	{
		std::cout << "ScavTrap " << name << " repaired " << amount << " points\n";
		--energyPoint;
		hitPoint += amount;
	}
	else
		std::cout << "ScavTrap " << name << " has not enough energy\n";
}

void	ScavTrap::guardGate()
{
	if (!hitPoint)
		return ;
	std::cout << name << " ScavTrap is now in Gate keeper mode\n";
}
