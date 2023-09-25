/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:32:28 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/04 20:28:36 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <sstream>

int main(int ac, char **av)
{
	std::ifstream			ifs;
	std::ofstream			ofs;
	std::stringstream		strstream;
	std::string				buffer;
	std::string				buffer2 = "";
	std::string::size_type	pre_i = 0;
	std::string::size_type	i = 0;
	int						s1_len;

	if (ac != 4)
		{std::cout << "usage : ./ex04 <filename> <word1> <word2>\n"; return 1;}
	ifs.open(av[1]);
	if (!ifs.good())
		{std::cout << "ifstream open error\n"; return 1;}
	ofs.open(static_cast<std::string>(av[1]) + ".replace");
	if (!ofs.good())
		{std::cout << "ofstream open error\n"; return 1;}
	strstream << ifs.rdbuf();
	ifs.close();
	buffer = strstream.str();
	if (*av[2])
	{
		s1_len = static_cast<std::string>(av[2]).length();
		while ((i = buffer.find(av[2], i + 1)) != std::string::npos)
		{
			buffer2 += buffer.substr(pre_i, i - pre_i) + av[3];
			pre_i = i + s1_len;
		}
		buffer2 += buffer.substr(pre_i, std::string::npos);
		ofs << buffer2;
	}
	else
		ofs << buffer;
	ofs.close();
	return 0;
}
