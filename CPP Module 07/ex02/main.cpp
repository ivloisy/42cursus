/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 05:06:22 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/10 16:33:56 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Character.hpp"

int main( void )
{
	try
	{
		std::cout << std::endl << "\033[4;33m" << "Type Int:" << "\033[0m" << std::endl;
		Array<int>	a(6);
		std::cout << std::endl << "\033[4;36m" << "Array a:" << "\033[0m" << std::endl;
		for (unsigned int i = 0; i < a.size() ; i++)
		{
			a[i] = i;
			std::cout << a[i] << std::endl;
		}
		std::cout << "size:\t" << a.size() << std::endl;

		Array<int>	b(a);
		std::cout << std::endl << "\033[4;36m" << "Array b:" << "\033[0m" << std::endl;
		for (unsigned int i = 0; i < b.size(); i++)
			std::cout << b[i] << std::endl;
		std::cout << "size:\t" << b.size() << std::endl;

		std::cout << std::endl << "\033[4;33m" << "Type Float:" << "\033[0m" << std::endl;
		Array<float>	c(6);
		std::cout << std::endl << "\033[4;36m" << "Array c:" << "\033[0m" << std::endl;
		for (unsigned int i = 0; i < c.size() ; i++)
		{
			c[i] = static_cast<float>(i);
			std::cout << c[i] << std::endl;
		}
		std::cout << "size:\t" << c.size() << std::endl;

		Array<float>	d(c);
		std::cout << std::endl << "\033[4;36m" << "Array d:" << "\033[0m" << std::endl;
		for (unsigned int i = 0; i < d.size(); i++)
		{
			d[i] /= 3;
			std::cout << d[i] << std::endl;
		}
		std::cout << "size:\t" << d.size() << std::endl;

		std::cout << std::endl << "\033[4;33m" << "Type Class:" << "\033[0m" << std::endl;

		Array<Character>	e(2);
		Array<Character>	f(e);

		e[0].setName("Bob");
		e[1].setAge(68);
		f[0].setAge(34);
		f[1].setName("Jim");

		std::cout << std::endl << "\033[4;36m" << "Array e:" << "\033[0m" << std::endl;
		for (unsigned int i = 0; i < e.size() ; i++)
		{
			std::cout << "e[" << i << "]:" << std::endl;
			std::cout << e[i] << std::endl;
		}
		std::cout << "size:\t" << e.size() << std::endl;

		std::cout << std::endl << "\033[4;36m" << "Array f:" << "\033[0m" << std::endl;
		for (unsigned int i = 0; i < f.size(); i++)
		{
			std::cout << "f[" << i << "]:" << std::endl;
			std::cout << f[i] << std::endl;
		}
		std::cout << "size:\t" << f.size() << std::endl;

		std::cout << std::endl << "\033[4;36m" << "Nimp:" << "\033[0m" << std::endl;
		std::cout << f[2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
