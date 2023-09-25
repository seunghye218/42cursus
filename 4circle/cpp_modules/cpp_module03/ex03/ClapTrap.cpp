/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:20:34 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/13 13:20:34 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: name("Default Name"), hitPoint(trapStat::C_HP), energyPoint(trapStat::C_EP), attackPoint(trapStat::C_AP)
{
	std::cout << "ClapTrap constructor called\n";
}

ClapTrap::ClapTrap(std::string name)
	: name(name), hitPoint(trapStat::C_HP), energyPoint(trapStat::C_EP), attackPoint(trapStat::C_AP)
{
	std::cout << name << " ClapTrap constructor called\n";
}

ClapTrap::~ClapTrap(void)
{
	std::cout << name << " ClapTrap destructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& claptrap) 
{
	*this = claptrap;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& claptrap)
{
	std::cout << name << " ClapTrap Copy constructor called\n";
	hitPoint = claptrap.hitPoint;
	energyPoint = claptrap.energyPoint;
	attackPoint = claptrap.attackPoint;
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (!hitPoint)
		{std::cout << "ClapTrap " << name << " is already dead\n"; return;}
	if (energyPoint)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackPoint << " points of damage!\n";
		--energyPoint;
	}
	else
		std::cout << "ClapTrap " << name << " has not enough energy\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!hitPoint)
		{std::cout << "ClapTrap " << name << " is already dead\n"; return;}
	std::cout << "ClapTrap " << name << " taked " << amount << " points of damage\n";
	if (hitPoint > amount)
		hitPoint -= amount;
	else
		hitPoint = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!hitPoint)
		{std::cout << "ClapTrap " << name << " is already dead\n"; return;}
	if (energyPoint)
	{
		std::cout << "ClapTrap " << name << " repaired " << amount << " points\n";
		--energyPoint;
		hitPoint += amount;
	}
	else
		std::cout << "ClapTrap " << name << " has not enough energy\n";
}
