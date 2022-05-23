/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 04:20:44 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/01 20:00:47 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	srand(time(NULL));

	AForm	*f1 = new ShrubberyCreationForm("Home");
	std::cout << *f1 << std::endl;
	std::cout << f1->getTarget() << std::endl;

	delete f1;

	Bureaucrat				bob("Bob", 3);
	Bureaucrat				jim("Jim", 150);
	ShrubberyCreationForm	f2("Tree");
	std::cout << f2 << std::endl;
	bob.signForm(f2);
	jim.signForm(f2);
	std::cout << f2 << std::endl;
	RobotomyRequestForm		f3("Robot");
	std::cout << f3 << std::endl;
	jim.executeForm(f3);
	jim.executeForm(f2);
	bob.executeForm(f2);
	bob.signForm(f3);
	std::cout << f3 << std::endl;
	bob.executeForm(f3);
	bob.executeForm(f3);
	jim.executeForm(f3);
	bob.executeForm(f3);
	bob.executeForm(f3);
	std::cout << f3 << std::endl;
	PresidentialPardonForm	f4("Arthur Dent");
	std::cout << f4 << std::endl;
	bob.executeForm(f4);
	bob.signForm(f4);
	bob.executeForm(f4);
	return 0;
}
