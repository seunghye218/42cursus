/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:39:22 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/18 14:58:36 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

struct s_floor	floor_;

Character::Character(void) : name("defalut")
{
	for (int i = 0; i < 4; ++i)
		slot[i] = 0;
}

Character::Character(std::string s) : name(s)
{
	for (int i = 0; i < 4; ++i)
		slot[i] = 0;
}

Character::Character(const Character& c) {*this = c;}

Character&Character::operator=(const Character& c)
{
	if (this != &c)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (slot[i])
				delete slot[i];
		}
		for (int i = 0; i < 4; ++i)
		{
			if (c.slot[i])
				slot[i] = c.slot[i]->clone();
		}
	}
	return *this;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; ++i)
	{
		if (slot[i])
			delete slot[i];
	}
}

std::string const& Character::getName() const {return name;}

void    Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; ++i)
		if (!slot[i])
			{slot[i] = m;return ;}
	std::cout << "Not enough slot\n";
}

void	Character::unequip(int i)
{
	if (i >= 0 && i < 4)
	{
		if (slot[i])
		{
			floor_.slot[floor_.idx] = slot[i];
			slot[i] = 0;
			++(floor_.idx);
		}
		else
			std::cout << "slot is empty\n";
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && slot[idx])
		slot[idx]->use(target);
	
}
