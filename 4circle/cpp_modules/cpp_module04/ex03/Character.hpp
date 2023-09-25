/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:44:34 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/18 14:59:10 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

struct	s_floor
{
	AMateria	*slot[100];
	int			idx;
};

class Character : public ICharacter
{
	private:
		const std::string	name;
		AMateria			*slot[4];
	public:
		Character(void);
		Character(std::string s);
		Character(const Character& c);
		Character&operator=(const Character& c);
		~Character(void);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};
