/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:23:15 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/13 14:16:10 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string);
		~ScavTrap(void);
		ScavTrap(const ScavTrap&);
		ScavTrap& operator=(const ScavTrap&);
		void	attack(const std::string&);
		void 	takeDamage(unsigned int);
		void 	beRepaired(unsigned int);

		void	guardGate(void);
};
