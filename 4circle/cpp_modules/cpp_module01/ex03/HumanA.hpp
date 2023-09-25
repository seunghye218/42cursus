/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:58:49 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/03 20:15:05 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class	HumanA
{
	private:
		string	name;
		Weapon	&weapon;
	public:
		HumanA(string humanName, Weapon &weaponType);
		void	attack(void);
};
