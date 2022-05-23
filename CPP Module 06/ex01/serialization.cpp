/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 08:14:38 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/04 09:02:28 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialization.hpp"

uintptr_t	serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data	*deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

int	main()
{
	Data		*bob;
	Data		*jim;
	uintptr_t	p;

	bob = new Data;
	bob->name = "Bob";
	bob->grade = 42;
	std::cout << "\t* 1 *" << std::endl;
	std::cout << "name:\t\t" << bob->name << std::endl;
	std::cout << "grade:\t\t" << bob->grade << std::endl;
	std::cout << "address:\t" << bob << std::endl << std::endl;
	p = serialize(bob);
	std::cout << "serialised:\t" << p << std::endl << std::endl;
	jim = deserialize(p);
	std::cout << "\t* 2 *" << std::endl;
	std::cout << "name:\t\t" << jim->name << std::endl;
	std::cout << "grade:\t\t" << jim->grade << std::endl;
	std::cout << "address:\t" << jim << std::endl << std::endl;

	delete bob;

	return 0;
}
