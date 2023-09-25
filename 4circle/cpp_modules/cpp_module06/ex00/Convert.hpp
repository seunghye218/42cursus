/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:35:51 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/24 12:00:30 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include <exception>
#include <limits>

using std::string;

class	Convert
{
	private:
		string	s;
		double	d;
	public:
		Convert(void);
		Convert(char*);
		Convert(const Convert&);;
		~Convert(void);
		Convert&operator=(const Convert&);

		void	displayChar(void);
		void	displayInt(void);
		void	displayFloat(void);
		void	displayDouble(void);
};
