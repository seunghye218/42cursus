/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:49:50 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/05 18:18:53 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

using std::string;

class	Weapon
{
	private:
		std::string	type;

	public:
		Weapon(string weaponType = "knife");
		const string&	getType(void);
		void			setType(string type);
};
