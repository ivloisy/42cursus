/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:03:27 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/20 19:50:31 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int	main(void)
{
	ScavTrap	bob;
	ScavTrap	bob2(bob);
	ClapTrap	jim;
	FragTrap	kim("Kim");
	FragTrap	kim2("Kim2");

	bob2.takeDamage(5);
	bob2.guardGate();
	bob2.takeDamage(100);
	bob2.beRepaired(5);
	bob2.guardGate();
	bob.attack("Gronaz");
	jim.attack("Gronaz");
	bob.takeDamage(2);
	bob.beRepaired(5);
	bob.takeDamage(7);
	bob.beRepaired(5);
	bob.takeDamage(100);
	kim.highFivesGuys();
	kim.attack("Gronaz");
	kim.attack("Gronaz");
	kim.attack("Gronaz");
	kim.takeDamage(100);
	kim.attack("Gronaz");
	kim.beRepaired(10);
	kim2.takeDamage(30);
	kim2.beRepaired(60);
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.attack("Gronaz");
	kim2.beRepaired(5);
	kim2.highFivesGuys();
	
	return 0;
}