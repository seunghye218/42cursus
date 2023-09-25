/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:36:39 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/03 19:16:03 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie  zb1("Zombie1");
    Zombie  *zb2;

    zb2 = newZombie("Zombie2");
    zb1.Announce();
    zb2->Announce();
    randomChump("Zombie3");

    delete zb2;

    return 0;
}