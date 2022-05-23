/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 00:23:09 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/10 22:50:34 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	return ;
}

Zombie::Zombie(std::string zombieName) : _name(zombieName)
{
	return ;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " has been destroyed !" << std::endl;
	return ;
}

void	Zombie::setName(std::string name, int i)
{
	std::ostringstream	number_str;
	
	number_str << i;
	this->_name = name + number_str.str();
	announce();
	return ;
}

void	Zombie::announce(void) const
{
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}
