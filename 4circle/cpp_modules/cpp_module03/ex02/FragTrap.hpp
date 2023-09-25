/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:23:15 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/13 14:15:18 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string);
		~FragTrap(void);
		FragTrap(const FragTrap&);
		FragTrap& operator=(const FragTrap&);
		void	attack(const std::string&);
		void 	takeDamage(unsigned int);
		void 	beRepaired(unsigned int);

		void	highFivesGuys(void);
};
