/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:15:56 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/20 17:57:06 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _n("Clap"), _hp(10), _ep(10), _ad(0)
{
	std::cout << "OK! The ClapTrap " << CYAN  << _n << END << " is in da place!" << std::endl;
	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Bye ClapTrap " << CYAN  << _n << END << ", you was a good soldier..." << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	*this = src;
	std::cout << "OK! A copy of the ClapTrap " << CYAN  << _n << END << " is in da place!" << std::endl;
	return ;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs)
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

ClapTrap::ClapTrap(std::string name) :_n(name), _hp(10), _ep(10), _ad(0)
{
	std::cout << "OK! The ClapTrap named " << CYAN  << _n << END << " is in da place!" << std::endl;
	return ;
}

void	ClapTrap::attack(std::string const &target)
{
	if (this->_ep > 0 && this->_hp > 0)
	{
		this->_ep--;
		std::cout << "ClapTrap " << CYAN <<  _n << END << " attack " << PURPLE << target << END << ", causing " << YELLOW << _ad << END << " points of damage!" << std::endl;
	}
	else
	{
		if (this->_hp == 0)
			std::cout << "ClapTrap " << CYAN <<  _n << END << " can't attack " << PURPLE << target << END << ", because it is KO." << std::endl;
		else
			std::cout << "ClapTrap " << CYAN <<  _n << END << " wants to attack " << PURPLE << target << END << ", but it doesn't have enough energy." << std::endl;
	}
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp > amount)
	{
		this->_hp -= amount;
		std::cout << CYAN  << _n << END << " takes " << RED << amount << END << " of damage. (" << _hp << "/100)"
		<< std::endl;
	}
	else
	{
		this->_hp = 0;
		std::cout << CYAN  << _n << END << " is KO." << std::endl;
	}
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hp > 0 && this->_ep > 0)
	{
		if (100 - this->_hp > amount)
		{
			this->_hp += amount;
			std::cout << CYAN  << _n << END << " is partially repaired. (" << _hp << "/100)"
			<< std::endl;
		}
		else
		{
			this->_hp = 100;
			std::cout << CYAN  << _n << END << " is fully repaired. (" << _hp << "/100)"
			<< std::endl;
		}
		this->_ep--;
	}
	else
	{
		if (this->_hp == 0)
			std::cout << CYAN  << _n << END << " is KO. It can't be repaired." << std::endl;
		else
			std::cout << CYAN  << _n << END << " doesn't have enough energy. It can't be repaired." << std::endl;
	}
	return ;
}
