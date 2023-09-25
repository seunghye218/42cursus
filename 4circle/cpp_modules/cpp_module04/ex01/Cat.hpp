/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:27:43 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/13 20:54:01 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal
{
	private:
		Brain*	brain;
	public:
		Cat(void);
		Cat(const Cat&);
		Cat&operator=(const Cat&);
		~Cat();

		void	makeSound(void) const {std::cout << "**Cat sound**\n";}
		Brain*	getBrain(void) {return brain;}
};
