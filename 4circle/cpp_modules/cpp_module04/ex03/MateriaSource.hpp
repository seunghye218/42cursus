/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:05:58 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/18 15:05:45 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include <string>

class	MateriaSource : public IMateriaSource
{
	private:
		AMateria		*slot[4];
	public:
		MateriaSource(void) {
			for (int i = 0; i < 4; ++i)
				slot[i] = 0;
		}
		MateriaSource(const MateriaSource&) {}
		MateriaSource&operator=(const MateriaSource&) {return *this;}
		~MateriaSource(void)
		{
			for (int i = 0; i < 4 && slot[i]; ++i)
				delete slot[i];
		}

		void learnMateria(AMateria* m)
		{
			for (int i = 0; i < 4; ++i)
				if (!slot[i])
					{slot[i] = m; return ;}
			std::cout << "Not enough slot\n";
		}

		AMateria* createMateria(std::string const & type)
		{
			for (int i = 0; i < 4 && slot[i]; ++i)
				if (!type.compare(slot[i]->getType()))
					return slot[i]->clone();
			return 0;
		}
};
