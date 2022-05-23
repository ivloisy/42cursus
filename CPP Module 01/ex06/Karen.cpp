/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 04:43:17 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/12 19:11:05 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen(void)
{
	return ;
}

Karen::~Karen()
{
	return ;
}

void	Karen::complain(std::string level)
{
	std::string	lvl[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	int	i;
	for (i = 0; i < 4; i++)
		if (!level.compare(lvl[i]))
			break ;
	switch (i)
	{
		case 0:
		{
			std::cout << "[ DEBUG ]" << std::endl;
			Karen::debug();
			__attribute__ ((fallthrough));
		}

		case 1:
		{
			std::cout << "[ INFO ]" << std::endl;
			Karen::info();
			__attribute__ ((fallthrough));
		}

		case 2:
		{
			std::cout << "[ WARNING ]" << std::endl;
			Karen::warning();
			__attribute__ ((fallthrough));
		}

		case 3:
		{
			std::cout << "[ ERROR ]" << std::endl;
			Karen::error();
			break;
		}

		default:
		{
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
		}
	}
}

void	Karen::debug(void)
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl << std::endl;
	return ;
}

void	Karen::info(void)
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl << std::endl;
	return ;
}

void	Karen::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl << std::endl;
	return ;
}

void	Karen::error(void)
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
	return ;
}
