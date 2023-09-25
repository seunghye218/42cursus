/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:23:59 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/24 13:32:17 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void    iter(T* p, size_t size, void (*f)(T))
{
    for (size_t i = 0; i < size; ++i)
        f(p[i]);
}

template <typename T>
void    ft_print(T p)
{
    std::cout << p << std::endl;
}
