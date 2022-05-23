/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 03:50:47 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/11 19:03:33 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) :	_name(name)
{
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}

void	HumanB::attack(void) const
{
	std::cout << _name << " attacks with his " << _weaponPtr->getType()
	<< std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weaponPtr = &weapon;
	return ;
}
