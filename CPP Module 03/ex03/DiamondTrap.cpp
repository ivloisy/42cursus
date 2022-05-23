/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 00:38:30 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/20 19:32:54 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ScavTrap(), FragTrap()
{
	this->_n = "Diamond";
	this->_ep = 50;
	ClapTrap::_n = _n + "_clap_name";
	std::cout << "OK! The DiamondTrap " << CYAN  << _n << END << " is in da place!" << std::endl;
	return ;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Bye DiamondpTrap " << CYAN  << _n << END << ", you was a good soldier..." << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ScavTrap(), FragTrap()
{
	*this = src;
	std::cout << "OK! A copy of the DiamondTrap " << CYAN  << _n << END << " is in da place!" << std::endl;
	return ;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &rhs)
{
	if (this != &rhs)
	{
		this->_n = rhs._n;
		ClapTrap::_n = _n + "_clap_name";
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_ad = rhs._ad;
	}
	return *this;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(), FragTrap()
{
	this->_n = name;
	this->_ep = 50;
	ClapTrap::_n = _n + "_clap_name";
	std::cout << "OK! The DiamondTrap " << CYAN  << _n << END << " is in da place!" << std::endl;
	return ;
}

void	DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "Name:\t\t" << CYAN  << _n << END << std::endl;										
	std::cout << "Clap Name:\t" << CYAN  << ClapTrap::_n << END << std::endl;
	return ;									
}
