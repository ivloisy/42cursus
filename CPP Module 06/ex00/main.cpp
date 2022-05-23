/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 01:50:09 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/04 06:28:53 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error\nPlease, enter a string representation of a literal in argument." << std::endl;
		return 1;
	}

	std::string	str(av[1]);

	Converter	conv(str);
	std::cout << conv;

	return 0;
}
