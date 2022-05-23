/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:05:14 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/19 17:25:24 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));
	Fixed const	c(Fixed(10) / Fixed(2) + Fixed(3) - Fixed(1));
	Fixed		d(c);
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
 	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
 	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	if (a != c)
		std::cout << "a != c" << std::endl;
	if (c == d)
		std::cout << "c == d" << std::endl;
	if (c <= d)
		std::cout << "c <= d" << std::endl;
	if (c >= d)
		std::cout << "c >= d" << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
	std::cout << Fixed::max(a, c) << std::endl;

	return 0;
}
