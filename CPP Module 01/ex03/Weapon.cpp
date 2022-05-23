/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 01:00:17 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/11 03:33:15 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}

const std::string	&Weapon::getType(void) const
{
	const std::string	&typeRef = _type;
	return(typeRef);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
	return ;
}
