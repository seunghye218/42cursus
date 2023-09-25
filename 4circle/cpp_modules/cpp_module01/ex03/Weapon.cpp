/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:39:23 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/05 18:18:55 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(string weaponType) : type(weaponType) {}

const string&	Weapon::getType(void)
{
	return this->type;
}
void			Weapon::setType(string type)
{
	this->type = type;
}