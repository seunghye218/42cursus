/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:31:40 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/04 19:10:24 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class	HumanB
{
	private:
		string	name;
		Weapon	*weapon;
	public:
		HumanB(string humanName);
		void	setWeapon(Weapon &weapon);
		void	attack(void);
};
