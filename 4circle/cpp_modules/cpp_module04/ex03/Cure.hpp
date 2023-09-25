/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:22:00 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/18 13:50:53 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class   Cure : public AMateria
{
	public:
		Cure(void) : AMateria("cure") {}
		Cure(const Cure&) {}
		~Cure(void) {}
		Cure&operator=(const Cure&) {return *this;}
		AMateria* clone() const {return new Cure;}
		void use(ICharacter& target)
		{
			std::cout << "* heals " << target.getName() << "'s wounds *\n";
		}
};
