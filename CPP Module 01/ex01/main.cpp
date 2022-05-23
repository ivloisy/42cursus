/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 02:28:05 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/10 23:01:32 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

# include <cstdlib>
# include <cstdio>

int	getNumber(void)
{
	char	input[256];
	int		N;
	
	std::cout << "Enter the number of zombie (1-100) : ";
	fgets (input, 256, stdin);
	N = atoi (input);
	if (N <= 0 || N > 100)
	{
		std::cerr << "It is not a good number !" << std::endl;
		return (0);
	}
	return (N);
}

int main(void)
{
	int		N;
	Zombie	*horde;
	
	std::cout << "WELCOME TO ZOMBIELAND !" << std::endl;
	N = 0;
	while (!N)
		N = getNumber();
	std::cout << "Zombie appearance :" << std::endl;
	horde = zombieHorde(N, "Zombie");
	std::cout << "Zombie destruction :" << std::endl;
	delete [] horde;
	return (0);
}