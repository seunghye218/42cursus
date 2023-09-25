/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:17:08 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/03 19:38:43 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

using std::string;

class   Zombie
{
	private:
		string	name;
	
	public:
		void    Announce(void);

		Zombie(string name = "Zombie");
		~Zombie(void);
};

Zombie  *newZombie(string name);
void    randomChump(string name);
