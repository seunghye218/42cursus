/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:28:21 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/13 20:39:51 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal
{
	private:
		Brain*	brain;
	public:
		Dog(void);
		Dog(const Dog&);
		Dog&operator=(const Dog&);
		~Dog();

		void	makeSound(void) const {std::cout << "**Dog sound**\n";}
		const Brain*	getBrain(void) const {return brain;}
};
