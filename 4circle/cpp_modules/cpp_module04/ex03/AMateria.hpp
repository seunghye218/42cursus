/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:44:12 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/18 14:30:29 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ICharacter;

class AMateria
{
	protected:
		const std::string	type;
	public:
		AMateria(std::string const & type) : type(type) {}
		AMateria(void) : type("void") {}
		AMateria(const AMateria& m) {*this = m;}
		AMateria&operator=(const AMateria&) {return *this;}
		virtual ~AMateria(void) {}

		std::string const & getType() const {return type;}
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter&) {std::cout << "* void *\n";}
};

class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0; 
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};
