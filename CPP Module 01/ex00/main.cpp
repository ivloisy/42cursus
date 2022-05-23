/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 00:35:44 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/10 23:05:53 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*heapZombie;

	std::cout << "WELCOME TO ZOMBIELAND !" << std::endl;
	heapZombie = newZombie("heapZombie");
	randomChump("stackZombie1");
	randomChump("stackZombie2");
	delete heapZombie;
	return (0);
}
