/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:03:32 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/03 20:01:06 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zb_horde;
	int		n = 5;

	zb_horde = zombieHorde(n, "zombie");
	for (int i = 0; i < n; ++i)
		zb_horde[i].Announce();
	delete [] zb_horde;
	return 0;
}
