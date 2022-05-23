/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:05:14 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/18 23:51:47 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

void	is_in_triangle(Point const	a, Point const	b, Point const	c, Point const	p, std::string s)
{
	if (bsp(a, b, c, p))
		std::cout << "\033[32m" << "The point " << s << p << " is in the triangle abc." << "\033[0m" << std::endl;
	else
		std::cout << "\033[31m" << "The point " << s << p << " is not in the triangle abc." << "\033[0m" << std::endl;
}

int	main(void)
{
	Point const	a(Fixed(2), Fixed(3));
	Point const	b(Fixed(4), Fixed(-1));
	Point const	c(Fixed(-3), Fixed(-3));
	
	std::cout << "We have a triangle abc with : a" << a
	<< ", b" << b << ", c" << c
	<< std::endl << std::endl;

	Point const	p1;
	Point const	p2(Fixed(-2.5f), Fixed(2.5f));
	Point const	p3(a);

	is_in_triangle(a, b, c, p1, "p1");
	is_in_triangle(a, b, c, p2, "p2");
	is_in_triangle(a, b, c, p3, "p3");
	
	return 0;
}
