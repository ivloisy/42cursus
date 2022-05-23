/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:54:34 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/23 18:05:49 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout	<< "An WrongAnimal appears." << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal()
{
	std::cout	<< "The WrongAnimal disappears." << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	*this = src;
	std::cout	<< "An copy of the WrongAnimal appears." << std::endl;
	return ;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &rhs)
{
	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}

std::string	WrongAnimal::getType() const
{
	return this->type;
}

void	WrongAnimal::makeSound() const
{
	std::cout	<< "* GRRRrrr... *" << std::endl;
	return ;
}
