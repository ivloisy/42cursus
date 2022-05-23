/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:03:27 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/20 20:00:10 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	pam("Pam");
	pam.whoAmI();
	pam.takeDamage(20);
	DiamondTrap	*pam2;
	pam2 = new DiamondTrap(pam);
	pam2->takeDamage(20);
	pam2->highFivesGuys();
	pam2->guardGate();
	pam.beRepaired(30);
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam.attack("Gronaz");
	pam2->takeDamage(20);
	pam2->beRepaired(10);
	pam2->takeDamage(60);
	pam2->beRepaired(10);
	delete pam2;
	
	return 0;
}