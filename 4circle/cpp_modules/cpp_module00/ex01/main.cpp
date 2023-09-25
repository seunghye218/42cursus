/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:22:48 by seunghye          #+#    #+#             */
/*   Updated: 2022/09/28 17:18:56 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	std::string	str;
	PhoneBook	pb;
	int			i = 0;

	while (1)
	{
		std::cout << "Enter one of commands(ADD, SEARCH, EXIT) : ";
		str = ft_getline();
		if (!str.compare("ADD"))
			pb.setContact(i++ % 8);
		else if (!str.compare("SEARCH"))
			pb.search(i < 8? i : 8);
		else if (!str.compare("EXIT"))
			return 0;
	}
	return 0;
}
