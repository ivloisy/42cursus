/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:51:31 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/25 18:07:42 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria constructor called" << std::endl;
	return ;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
	return ;
}

AMateria::AMateria(AMateria const &src)
{
	*this = src;
	std::cout << "AMateria copy constructor called" << std::endl;
	return ;
}

AMateria	&AMateria::operator=(AMateria const &rhs)
{
	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}

std::string const	&AMateria::getType() const
{
	return this->_type;
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "* does nothing at " << target.getName() << " *" << std::endl;
	return ;
}
