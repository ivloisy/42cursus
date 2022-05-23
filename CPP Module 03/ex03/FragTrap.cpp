/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:49:53 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/20 19:39:33 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_n = "Frag";
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
	std::cout << "OK! The FragTrap " << CYAN << _n << END << " is in da place!" << std::endl;
	return ;
}

FragTrap::~FragTrap()
{
	std::cout << "Bye FragTrap " << CYAN  << _n << END << ", you was a good soldier..." << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap()
{
	*this = src;
	std::cout << "OK! A copy of the FragTrap " << CYAN  << _n << END << " is in da place!" << std::endl;
	return ;
}

FragTrap	&FragTrap::operator=(FragTrap const &rhs)
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

FragTrap::FragTrap(std::string name) : ClapTrap()
{
	this->_n = name;
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
	std::cout << "OK! The FragTrap named " << CYAN  << _n << END << " is in da place!" << std::endl;
	return ;
}

void	FragTrap::attack(std::string const &target)
{
	if (this->_ep > 0 && this->_hp > 0)
	{
		this->_ep--;
		std::cout << "FragTrap " << CYAN <<  _n << END << " attack " << PURPLE << target << END << ", causing " << YELLOW << _ad << END << " points of damage!" << std::endl;
	}
	else
	{
		if (this->_hp == 0)
			std::cout << "FragTrap " << CYAN <<  _n << END << " can't attack " << PURPLE << target << END << ", because it is KO." << std::endl;
		else
			std::cout << "FragTrap " << CYAN <<  _n << END << " wants to attack " << PURPLE << target << END << ", but it doesn't have enough energy." << std::endl;
	}
	return ;
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_ep > 0 && this->_hp > 0)
		std::cout << CYAN  << _n << END << " gives you a high five!" << std::endl;
	else
		std::cout << CYAN  << _n << END << " can't to give you a high five!" << std::endl;
	return ;
}
