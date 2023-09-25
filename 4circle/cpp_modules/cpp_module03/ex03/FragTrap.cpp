/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:22:56 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/13 13:53:08 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << name << " FragTrap constructor called\n";
	hitPoint = trapStat::F_HP;
	energyPoint = trapStat::F_EP;
	attackPoint = trapStat::F_AP;
}

FragTrap::~FragTrap(void)
{
	std::cout << name << " FragTrap destructor called\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << name << " FragTrap constructor called\n";
	hitPoint = trapStat::F_HP;
	energyPoint = trapStat::F_EP;
	attackPoint = trapStat::F_AP;
}

FragTrap& FragTrap::operator=(const FragTrap& fragTrap)
{
	std::cout << name << " FragTrap Copy constructor called\n";
	hitPoint = fragTrap.hitPoint;
	energyPoint = fragTrap.energyPoint;
	attackPoint = fragTrap.attackPoint;
	return *this;
}

FragTrap::FragTrap(const FragTrap& fragTrap)
{
	*this = fragTrap;
}

void	FragTrap::attack(const std::string &target)
{
	if (!hitPoint)
		{std::cout << "FragTrap " << name << " is already dead\n"; return;}
	if (energyPoint)
	{
		std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackPoint << " points of damage!\n";
		--energyPoint;
	}
	else
		std::cout << "FragTrap " << name << " has not enough energy\n";
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (!hitPoint)
		{std::cout << "FragTrap " << name << " is already dead\n"; return;}
	std::cout << "FragTrap " << name << " taked " << amount << " points of damage\n";
	if (hitPoint > amount)
		hitPoint -= amount;
	else
		hitPoint = 0;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (!hitPoint)
		{std::cout << "FragTrap " << name << " is already dead\n"; return;}
	if (energyPoint)
	{
		std::cout << "FragTrap " << name << " repaired " << amount << " points\n";
		--energyPoint;
		hitPoint += amount;
	}
	else
		std::cout << "FragTrap " << name << " has not enough energy\n";
}

void	FragTrap::highFivesGuys(void)
{
	if (!hitPoint)
		return ;
	std::cout << name << " highFivesGuys!\n";
}
