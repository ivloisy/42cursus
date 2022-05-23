/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:13:49 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/25 13:08:41 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout	<< "An Cat appears." << std::endl;
	return ;
}

Cat::~Cat()
{
	delete brain;
	std::cout	<< "The Cat disappears." << std::endl;
	return ;
}

Cat::Cat(Cat const &src) : AAnimal()
{
	*this = src;
	std::cout	<< "An copy of the Cat appears." << std::endl;
	return ;
}

Cat	&Cat::operator=(Cat const &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.getType();
		this->brain = new Brain(*rhs.brain);
	}
	return *this;			
}

void	Cat::makeSound() const
{
	std::cout << "* MEOW *" << std::endl;
	return ;
}

Brain	*Cat::getBrain() const
{
	return this->brain;
}
