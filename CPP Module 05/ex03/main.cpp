/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 04:20:44 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/01 21:01:52 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	Intern	intern;
	AForm	*formPtr;
	formPtr = intern.makeForm("Blablabla", "Arthur Dent");
	formPtr = intern.makeForm("PresidentialPardonForm", "Arthur Dent");
	Bureaucrat	bob("Bob", 5);
	bob.executeForm(*formPtr);
	bob.signForm(*formPtr);
	bob.executeForm(*formPtr);
	delete formPtr;
	return 0;
}
