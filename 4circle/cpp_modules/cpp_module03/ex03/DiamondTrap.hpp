/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:23:15 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/12 15:59:14 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		const std::string	name;
	public:
		DiamondTrap(void);
		DiamondTrap(std::string);
		~DiamondTrap(void);
		DiamondTrap(const DiamondTrap&);
		DiamondTrap& operator=(const DiamondTrap&);
		void	attack(const std::string&);
		void 	takeDamage(unsigned int);
		void 	beRepaired(unsigned int);

		void	whoAmI(void);
};
