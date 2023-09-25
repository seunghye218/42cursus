/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:23:57 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/24 17:29:37 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#define SIZE 10

int main()
{
    int     n[SIZE];
    float   f[SIZE];
    char    s[SIZE];

    for (int i = 0; i < SIZE; ++i)
    {
        n[i] = i;
        f[i] = i + 0.42f;
        s[i] = 'a';
    }

    ::iter(n, SIZE, ft_print<int>);
    ::iter(f, SIZE, ft_print<float>);
    ::iter(s, SIZE, ft_print);

    return 0;
}