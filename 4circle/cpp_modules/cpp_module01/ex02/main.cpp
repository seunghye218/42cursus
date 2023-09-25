/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:28:16 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/05 14:52:03 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using std::string;

int main(void)
{
	string	str = "HI THIS IS BRAIN";
	string	*stringPTR = &str;
	string	&stringREF = str;

	std::cout << "The memory address of the string variable : " << static_cast<void *>(&str) << std::endl
			  << "The memory address held by stringPTR      : " << static_cast<void *>(stringPTR) << std::endl
			  << "The memory address held by stringREF      : " << static_cast<void *>(&stringREF) << std::endl
	
			<< "The value of the string variable  : " << str << std::endl
			<< "The value pointed to by stringPTR : " << *stringPTR << std::endl
			<< "The value pointed to by stringREF : " << stringREF << std::endl;

	return 0;
}