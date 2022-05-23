/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:03:08 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/25 19:27:23 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria()
{
	this->_type = "ice";
	std::cout << "Ice constructor called" << std::endl;
	return ;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
	return ;
}

Ice::Ice(Ice const &src) : AMateria()
{
	*this = src;
	std::cout << "Ice copy constructor called" << std::endl;
	return ;
}

Ice	&Ice::operator=(Ice const &rhs)
{
	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}

AMateria	*Ice::clone() const
{
	return new Ice(*this);
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return ;
}
