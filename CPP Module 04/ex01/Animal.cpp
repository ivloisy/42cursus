/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:54:34 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/23 18:48:46 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout	<< "An Animal appears." << std::endl;
	return ;
}

Animal::~Animal()
{
	std::cout	<< "The Animal disappears." << std::endl;
	return ;
}

Animal::Animal(Animal const &src)
{
	*this = src;
	std::cout	<< "An copy of the Animal appears." << std::endl;
	return ;
}

Animal	&Animal::operator=(Animal const &rhs)
{
	if (this != &rhs)
		this->type = rhs.getType();
	return *this;			
}

std::string	Animal::getType() const
{
	return this->type;
}

void	Animal::makeSound() const
{
	std::cout	<< "* GRRRrrr... *" << std::endl;
	return ;
}
