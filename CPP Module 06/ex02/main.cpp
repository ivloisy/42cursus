/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:28:03 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/04 11:08:23 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <ctime>
#include <cstdlib>

Base	*generate(void)
{
	Base	*p = NULL;
	int		i = rand() % 3;

	switch (i)
	{
		case 0:
			p = new A;
			break;
		
		case 1:
			p = new B;
			break;
		
		default:
			p = new C;
			break;
	}

	return p;
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		Base	b = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch(const std::exception &e)
	{
	}
	
	try
	{
		Base	b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	}
	catch(const std::exception &e)
	{
	}

	try
	{
		Base	b = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	}
	catch(const std::exception &e)
	{
	}
}

int	main()
{
	srand(time(NULL));
	Base	*p = NULL;

	p = generate();
	identify(p);
	identify(*p);

	delete p;

	return 0;
}
