/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:41:50 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/12 18:47:06 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error : Invalid argument" << std::endl;
		return (1);
	}
	
	Karen	karen;
	karen.complain(av[1]);
	return (0);
}
