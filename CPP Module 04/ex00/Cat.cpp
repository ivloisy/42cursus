/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:13:49 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/23 17:46:06 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout	<< "An Cat appears." << std::endl;
	return ;
}

Cat::~Cat()
{
	std::cout	<< "The Cat disappears." << std::endl;
	return ;
}

Cat::Cat(Cat const &src) : Animal()
{
	*this = src;
	std::cout	<< "An copy of the Cat appears." << std::endl;
	return ;
}

Cat	&Cat::operator=(Cat const &rhs)
{
	if (this != &rhs)
		this->type = rhs.getType();
	return *this;			
}

void	Cat::makeSound() const
{
	std::cout	<< "* MEOW *" << std::endl;
	return ;
}
