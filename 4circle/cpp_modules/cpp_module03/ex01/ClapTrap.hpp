/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:15:01 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/13 14:14:31 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	ClapTrap
{
	protected:
		const std::string	name;
		unsigned int	hitPoint;
		unsigned int	energyPoint;
		unsigned int	attackPoint;
	public:
		ClapTrap(void);
		ClapTrap(std::string);
		ClapTrap(const ClapTrap&);
		ClapTrap& operator=(const ClapTrap&);
		virtual	~ClapTrap(void);
		virtual void	attack(const std::string&);
		virtual void	takeDamage(unsigned int);
		virtual void	beRepaired(unsigned int);

		inline unsigned int	getAP(void) {return attackPoint;}
		void	print_status(void)
		{
			std::cout << "name : " << name << std::endl
					<< "HP : " << hitPoint << std::endl
					<< "EP : " << energyPoint << std::endl
					<< "AP : " << attackPoint << std::endl;
		}
};

namespace	trapStat
{
	const unsigned	int	C_HP = 10;
	const unsigned	int	C_EP = 10;
	const unsigned	int	C_AP = 0;

	const unsigned	int	S_HP = 100;
	const unsigned	int	S_EP = 50;
	const unsigned	int	S_AP = 20;
};
