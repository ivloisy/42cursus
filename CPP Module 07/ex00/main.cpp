/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 05:06:22 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/10 15:03:23 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include "Character.hpp"

#include <iomanip>

int main( void )
{
	std::cout << std::fixed;
	std::cout << std::setprecision(1);
	std::cout << std::endl << "\033[4;33m" << "Type Int:" << "\033[0m" << std::endl;
	int a = 2;
	int b = 3;
	int	x = 2;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << ", x = " << x << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::cout << "max( a, x ) = " << ::min( a, x ) << std::endl;
	std::cout << "max( a, x ) = " << ::max( a, x ) << std::endl;

	std::cout << std::endl << "\033[4;33m" << "Type String:" << "\033[0m" << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << std::endl << "\033[4;33m" << "Type Float:" << "\033[0m" << std::endl;
	float	af = 2.5f;
	float	bf = 3.0f;
	float	xf = 2.5f;

	::swap( af, bf );
	std::cout << "a = " << af << ", bf = " << bf << ", xf = " << xf << std::endl;
	std::cout << "min( af, bf ) = " << ::min( af, bf ) << std::endl;
	std::cout << "max( af, bf ) = " << ::max( af, bf ) << std::endl;
	std::cout << "max( af, xf ) = " << ::min( af, xf ) << std::endl;
	std::cout << "max( af, xf ) = " << ::max( af, xf ) << std::endl;

	std::cout << std::endl << "\033[4;33m" << "Type Pointer:" << "\033[0m" << std::endl;
	int *p = &a;
	int *q = &b;

	std::cout << "p = " << p << ", q = " << q << std::endl;
	::swap( p, q );
	std::cout << "p = " << p << ", q = " << q << std::endl;
	std::cout << "min( p, q ) = " << ::min( p, q ) << std::endl;
	std::cout << "max( p, q ) = " << ::max( p, q ) << std::endl;

	std::cout << std::endl << "\033[4;33m" << "Type Reference:" << "\033[0m" << std::endl;
	int &r = a;
	int &s = b;

	std::cout << "r = " << r << ", s = " << s << std::endl;
	::swap( r, s );
	std::cout << "r = " << r << ", s = " << s << std::endl;
	std::cout << "min( r, s ) = " << ::min( r, s ) << std::endl;
	std::cout << "max( r, s ) = " << ::max( r, s ) << std::endl;

	std::cout << std::endl << "\033[4;33m" << "Type Class:" << "\033[0m" << std::endl;
	Character	bob("Bob", 34);
	Character	jim("Jim", 68);
	std::cout << "Bob:" << std::endl << bob << std::endl;
	std::cout << "Jim:" << std::endl << jim << std::endl;
	std::cout << "The youngest is " << ::min( bob, jim ).getName() << std::endl;
	::swap(bob, jim);
	std::cout << "Bob:" << std::endl << bob << std::endl;
	std::cout << "Jim:" << std::endl << jim << std::endl;
	std::cout << "The oldest is " << ::max( bob, jim ).getName() << std::endl;

	return 0;
}
