/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:21:24 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/25 15:53:01 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iterator>
#include <stdexcept>

template <typename Container>
typename Container::iterator	easyfind(Container& c, int n)
{
	typename Container::iterator	iter = std::find(c.begin(), c.end(), n);
	if (iter == c.end() && *c.end() != n)
		throw std::runtime_error("no such arg");
	return iter;
}
