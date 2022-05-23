/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 00:44:30 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/18 19:55:59 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0)
{
	return ;
}

Point::~Point()
{
	return ;
}

Point::Point(Point const &src) : x(src.x), y(src.y)
{
	*this = src;
	return ;
}

Point::Point(Fixed const a, Fixed const b) : x(a), y(b)
{
	return ;
}

Point	&Point::operator=(Point const &rhs)
{
	(void)rhs;
	return *this;	
}

float	Point::getX(void) const
{
	return this->x.toFloat();
}

float	Point::getY(void) const
{
	return this->y.toFloat();
}

std::ostream	&operator<<(std::ostream &o, const Point &rhs)
{
	o << "(" << rhs.getX() << "," << rhs.getY() << ")";
	return (o);
}
