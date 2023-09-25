/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:20:24 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/13 20:49:52 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain constructor called\n";
	for (int i = 0; i < 100;++i)
		ideas[i] = "idea";
}

Brain::Brain(const Brain& brain)
{
	std::cout << "Brain Copy constructor called\n";
	*this = brain;
}

Brain::~Brain(void) {std::cout << "Brain Destructor called\n";}

Brain&Brain::operator=(const Brain& brain)
{
	if (this != &brain)
	{
		for (int i = 1; i < 100;++i)
			ideas[i] = brain.ideas[i];
	}
	return *this;
}

const std::string	Brain::getIdea(int i) const
{
	if (0 <= i && i < 100)
		return ideas[i];
	return 0;
}

void	Brain::setIdea(int i, std::string idea)
{
	if (0 <= i && i < 100)
		ideas[i] = idea;
}
