/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:27:43 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/13 21:11:20 by seunghye         ###   ########.fr       */
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

		void	makeSound(void) {std::cout << "**Cat sound**\n";}
		Brain*	getBrain(void) {return brain;}
};
