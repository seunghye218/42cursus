/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:38:47 by seunghye          #+#    #+#             */
/*   Updated: 2022/10/06 19:32:30 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class   Point
{
    private:
        Fixed const x;
        Fixed const y;

    public:
        Point(void);
        Point(const float, const float);
        ~Point(void);
        Point(const Point&);
        Point&  operator=(const Point&);

        const Fixed   getX(void);
        const Fixed   getY(void);
        
};

bool    bsp( Point const a, Point const b, Point const c, Point const point);
