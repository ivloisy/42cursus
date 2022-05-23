/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:03:08 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/25 19:27:07 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria()
{
	this->_type = "cure";
	std::cout << "Cure constructor called" << std::endl;
	return ;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
	return ;
}

Cure::Cure(Cure const &src) : AMateria()
{
	*this = src;
	std::cout << "Cure constructor called" << std::endl;
	return ;
}

Cure	&Cure::operator=(Cure const &rhs)
{
	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}

AMateria	*Cure::clone() const
{
	return new Cure(*this);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	return ;
}
