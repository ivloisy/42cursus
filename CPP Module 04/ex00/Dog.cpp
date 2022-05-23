/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:13:49 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/23 17:27:46 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout	<< "An Dog appears." << std::endl;
	return ;
}

Dog::~Dog()
{
	std::cout	<< "The Dog disappears." << std::endl;
	return ;
}

Dog::Dog(Dog const &src) : Animal()
{
	*this = src;
	std::cout	<< "An copy of the Dog appears." << std::endl;
	return ;
}

Dog	&Dog::operator=(Dog const &rhs)
{
	if (this != &rhs)
		this->type = rhs.getType();
	return *this;			
}

void	Dog::makeSound() const
{
	std::cout	<< "* WOW *" << std::endl;
	return ;
}
