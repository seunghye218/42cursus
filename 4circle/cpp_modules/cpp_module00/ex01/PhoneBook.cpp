/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:47:10 by seunghye          #+#    #+#             */
/*   Updated: 2022/09/28 17:17:58 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>

enum e_contact e_c;

std::string	Contact::getMember(int e)
{
	switch (e)
	{
		case FIRST : return this->_firstName;
		case LAST : return this->_lastName;
		case NICK : return this->_nickName;
		case NB : return this->_phoneNumber;
		case SECRET : return this->_darkestSecret;
	}
	return 0;
}

void	Contact::setMember(int e, std::string str)
{
	switch (e)
	{
		case FIRST : this->_firstName = str; break;
		case LAST : this->_lastName = str; break;
		case NICK : this->_nickName = str; break;
		case NB : this->_phoneNumber = str; break;
		case SECRET : this->_darkestSecret = str; break;
	}
}


std::string	ft_getline(void)
{
	std::string	str;

	if (!std::getline(std::cin, str))
	{
		std::cout << "getline error\n";
		exit(1);
	}
	return str;
}

static std::string	get_str(int e)
{
	std::string	str;
	std::string	s;

	switch (e)
	{
		case FIRST : s = "First Name: "; break;
		case LAST : s = "Last Name: "; break;
		case NICK : s = "Nickname: "; break;
		case NB : s = "Phone Number: "; break;
		case SECRET : s = "Darkest Secret: "; break;
	}
	do
	{
		std::cout << s;
		str = ft_getline();
	}
	while (str.empty());
	return str;
}

Contact	PhoneBook::getContact(int i)
{
	return this->_contact[i];
}

void	PhoneBook::setContact(int i)
{
	this->_contact[i].setMember(FIRST, get_str(FIRST));
	this->_contact[i].setMember(LAST, get_str(LAST));
	this->_contact[i].setMember(NICK, get_str(NICK));
	this->_contact[i].setMember(NB, get_str(NB));
	this->_contact[i].setMember(SECRET, get_str(SECRET));
}

static void	my_print(std::string str)
{
	if (str.length() <= 10)
		std::cout << std::setw(10) << str << "|";
	else
	{
		std::string str2 = str.substr(0, 9);
		std::cout << str2 << ".|";
	}
}

void	PhoneBook::search(int i)
{
	std::string	str;

	std::cout << "--------------------------------------------\n"
			<< "     index|first name| last name|  nickname|\n"
			<< "--------------------------------------------\n";
	for (int j = 0; j < i; ++j)
	{
		std::cout << std::setw(10) << j << "|";
		my_print((*this).getContact(j).getMember(FIRST));
		my_print((*this).getContact(j).getMember(LAST));
		my_print((*this).getContact(j).getMember(NICK));
		std::cout << std::endl;
	}
	std::cout << "--------------------------------------------\n"
			<< "Enter index: ";
	str = ft_getline();
	i = *(str.begin()) - '0';
	if (i >= 0 && i < 8 && str.length() == 1)
	{
		if ((*this).getContact(i).getMember(FIRST).empty())
		{
			std::cout << "non-existent contact\n"
					<< "--------------------------------------------\n";
			return ;
		}
		std::cout << "Index: " << i << std::endl
				<< "First name: " << (*this).getContact(i).getMember(FIRST) << std::endl
				<< "Last name: " << (*this).getContact(i).getMember(LAST) << std::endl
				<< "Nickname: " << (*this).getContact(i).getMember(NICK) << std::endl
				<< "Phone Number: " << (*this).getContact(i).getMember(NB) << std::endl
				<< "Darkest Secret: " << (*this).getContact(i).getMember(SECRET) << std::endl
				<< "--------------------------------------------\n";
	}
	else
		std::cout << "the index is out of range or wrong\n";
	return ;
}
