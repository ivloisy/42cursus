/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:13:49 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/23 18:08:30 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout	<< "An WrongCat appears." << std::endl;
	return ;
}

WrongCat::~WrongCat()
{
	std::cout	<< "The WrongCat disappears." << std::endl;
	return ;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal()
{
	*this = src;
	std::cout	<< "An copy of the WrongCat appears." << std::endl;
	return ;
}

WrongCat	&WrongCat::operator=(WrongCat const &rhs)
{
	if (this != &rhs)
		this->type = rhs.getType();
	return *this;			
}

void	WrongCat::makeSound() const
{
	std::cout	<< "* MEOW *" << std::endl;
	return ;
}
