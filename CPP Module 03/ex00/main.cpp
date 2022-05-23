/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:03:27 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/20 18:07:19 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	bob;
	ClapTrap	jim("Jim");
	ClapTrap	jim2(jim);

	jim2.takeDamage(5);
	jim2.takeDamage(20);
	jim2.beRepaired(5);
	jim2.attack("Gronaz");
	bob.attack("Gronaz");
	bob.takeDamage(2);
	bob.beRepaired(5);
	bob.takeDamage(7);
	bob.beRepaired(100);
	bob.takeDamage(10);
	bob.attack("Gronaz");
	bob.attack("Gronaz");
	bob.attack("Gronaz");
	bob.attack("Gronaz");
	bob.attack("Gronaz");
	bob.attack("Gronaz");
	bob.attack("Gronaz");
	bob.attack("Gronaz");
	return 0;
}