/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 03:12:26 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/01 03:36:47 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern constructor called" << std::endl;
	return ;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
	return ;
}

Intern::Intern(Intern const &src)
{
	*this = src;
	std::cout << "Intern copy constructor called" << std::endl;
	return ;
}

Intern	&Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return *this;
}

AForm	*Intern::makeForm(std::string form, std::string target)
{
	std::string	f[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int	i;

	for (i = 0; i < 3; i++)
		if (!form.compare(f[i]))
			break ;
	std::cout << "Intern creates ";
	switch (i)
	{
		case 0:
		{
			std::cout << form << "." << std::endl;
			return new ShrubberyCreationForm(target);
		}
		case 1:
		{
			std::cout << form << "." << std::endl;
			return new RobotomyRequestForm(target);
		}
		case 2:
		{
			std::cout << form << "." << std::endl;
			return new PresidentialPardonForm(target);
		}
		default:
		{
			std::cout << "nothing." << std::endl;
			return NULL;
		}
	}
}
