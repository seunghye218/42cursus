/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:17:08 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/03 19:46:12 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

using std::string;

class   Zombie
{
	private:
		string	name;
	
	public:
		void    Announce(void);
		void	setName(string name);

		Zombie(string name = "Zombie");
		~Zombie(void);
};

Zombie	*zombieHorde( int N, std::string name );
