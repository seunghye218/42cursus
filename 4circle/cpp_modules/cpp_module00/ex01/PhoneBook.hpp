/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:52:21 by seunghye          #+#    #+#             */
/*   Updated: 2022/09/28 17:12:07 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>

class   Contact
{
	private:
		std::string    _firstName;
		std::string    _lastName;
		std::string    _nickName;
		std::string    _phoneNumber;
		std::string    _darkestSecret;
	public:
		std::string	getMember(int e);
		void		setMember(int e, std::string);
		Contact(void)
		{
			_firstName = "";
			_lastName = "";
			_nickName = "";
			_phoneNumber = "";
			_darkestSecret = "";
		}
};

class   PhoneBook
{
	private:
		Contact _contact[8];
	public:
		Contact	getContact(int i);
		void	setContact(int i);
		void	search(int i);
};

enum	e_contact
{
	FIRST,
	LAST,
	NICK,
	NB,
	SECRET
};

std::string	ft_getline(void);
