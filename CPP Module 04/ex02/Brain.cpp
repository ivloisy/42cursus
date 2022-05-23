/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 20:10:24 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/24 21:14:07 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	static std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

	for (int i = 0; i < 100; i++)
	{
		ideas[i].resize(10);
		for (int j = 0; j < 10; j++)
			ideas[i][j] = charset[rand() % charset.length()];
	}
	std::cout << "Brain constructor called" << std::endl;
	return;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
	return ;
}

Brain::Brain(Brain const &src)
{
	*this = src;
	std::cout << "Brain copy constructor called" << std::endl;
	return ;
}

Brain	&Brain::operator=(Brain const &rhs)
{
	if (this != &rhs)
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
	return *this;
}

void	Brain::printIdeas() const
{
	std::cout << this << "{" << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << "\t" << this->ideas[i] << std::endl;
	std::cout << "}" << std::endl;
}
