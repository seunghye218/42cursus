/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:28:08 by seunghye          #+#    #+#             */
/*   Updated: 2022/09/28 14:55:40 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	if (!*(++av) && ac)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (; *av; ++av)
			for (; **av; ++(*av))
				std::cout << static_cast<char>(std::toupper(**av));
	}
	std::cout << std::endl;
	return (0);
}
