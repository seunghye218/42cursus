/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:52:17 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/18 13:09:11 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class   Ice : public AMateria
{
	public:
		Ice(void) : AMateria("ice") {}
		Ice(const Ice&) {}
		~Ice(void) {}
		Ice&operator=(const Ice&) {return *this;}
		AMateria* clone() const {return new Ice;}
		void use(ICharacter& target)
		{
			std::cout  <<"* shoots an ice bolt at "<< target.getName() << " *\n";
		}
};
