/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:01:19 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/25 13:01:36 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout	<< "An AAnimal appears." << std::endl;
	return ;
}

AAnimal::~AAnimal()
{
	std::cout	<< "The AAnimal disappears." << std::endl;
	return ;
}

AAnimal::AAnimal(AAnimal const &src)
{
	*this = src;
	std::cout	<< "An copy of the AAnimal appears." << std::endl;
	return ;
}

AAnimal	&AAnimal::operator=(AAnimal const &rhs)
{
	if (this != &rhs)
		this->type = rhs.getType();
	return *this;			
}

std::string	AAnimal::getType() const
{
	return this->type;
}
