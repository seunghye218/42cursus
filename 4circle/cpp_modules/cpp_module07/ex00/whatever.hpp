/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:16:14 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/23 11:22:44 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void    swap(T &a, T &b)
{
    T   temp;

    temp = a;
    a = b;
    b = temp;
}

template <typename T>
T   min(T a, T b)
{
    return a < b ? a : b;
}

template <typename T>
T   max(T a, T b)
{
    return a > b ? a : b;
}
