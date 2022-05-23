/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 03:33:03 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/20 19:42:01 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_n = "Scav";
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
	std::cout << "OK! The ScavTrap " << CYAN << _n << END << " is in da place!" << std::endl;
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Bye ScavTrap " << CYAN  << _n << END << ", you was a good soldier..." << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap()
{
	*this = src;
	std::cout << "OK! A copy of the ScavTrap " << CYAN  << _n << END << " is in da place!" << std::endl;
	return ;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs)
{
	if (this != &rhs)
	{
		this->_n = rhs._n;
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_ad = rhs._ad;
	}
	return *this;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap()
{
	this->_n = name;
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
	std::cout << "OK! The ScavTrap named " << CYAN  << _n << END << " is in da place!" << std::endl;
	return ;
}

void	ScavTrap::attack(std::string const &target)
{
	if (this->_ep > 0 && this->_hp > 0)
	{
		this->_ep--;
		std::cout << "ScavTrap " << CYAN <<  _n << END << " attack " << PURPLE << target << END << ", causing " << YELLOW << _ad << END << " points of damage!" << std::endl;
	}
	else
	{
		if (this->_hp == 0)
			std::cout << "ScavTrap " << CYAN <<  _n << END << " can't attack " << PURPLE << target << END << ", because it is KO." << std::endl;
		else
			std::cout << "ScavTrap " << CYAN <<  _n << END << " wants to attack " << PURPLE << target << END << ", but it doesn't have enough energy." << std::endl;
	}
	return ;
}

void	ScavTrap::guardGate()
{
	if (this->_ep > 0 && this->_hp > 0)
		std::cout << CYAN  << _n << END << " have enterred in Gate keeper mode." << std::endl;
	else
		std::cout << CYAN  << _n << END << " can't to enter in Gate keeper mode." << std::endl;
	return ;
}
