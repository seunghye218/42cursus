/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:04:14 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/03 20:04:24 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Zombie.hpp"

Zombie	*zombieHorde( int N, std::string name )
{
	Zombie	*horde = new Zombie[N];
	std::stringstream	s;

	for (int i = 0; i < N; ++i)
	{
		s << i;
		horde[i].setName(name + s.str());
		s.str("");
	}
	return horde;
}
