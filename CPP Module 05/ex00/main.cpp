/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 04:20:44 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/01 18:32:19 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	*bob = NULL;
	Bureaucrat	*jim = NULL;
	Bureaucrat	*kim = NULL;
	Bureaucrat	*pam = NULL;

	try
	{
		bob = new Bureaucrat("Bob", 150);
		std::cout << *bob << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "The bureaucrat cannot be created because " << e.what() << std::endl;
	}

	try
	{
		jim = new Bureaucrat("Jim", 1);
		std::cout << *jim << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << "The bureaucrat cannot be created because " << e.what() << std::endl;
	}
	
	try
	{
		kim = new Bureaucrat("Kim", 151);
		std::cout << *kim << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "The bureaucrat cannot be created because " << e.what() << std::endl;
	}

	try
	{
		pam = new Bureaucrat("Pam", 0);
		std::cout << *pam << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << "The bureaucrat cannot be created because " << e.what() << std::endl;
	}
	
	try
	{
		bob->downGrade();
	}
	catch(const std::exception &e)
	{
		std::cout << *bob << " cannot be downgraded because " << e.what() << std::endl;
	}

	try
	{
		bob->upGrade();
	}
	catch(const std::exception &e)
	{
		std::cout << *bob << " cannot be upgraded because " << e.what() << std::endl;
	}
	
	try
	{
		jim->upGrade();
	}
	catch(const std::exception &e)
	{
		std::cout << *jim << " cannot be upgraded because " << e.what() << std::endl;
	}
	
	try
	{
		jim->downGrade();
	}
	catch(const std::exception &e)
	{
		std::cout << *jim << " cannot be downgraded because " << e.what() << std::endl;
	}

	delete bob;
	delete jim;
	delete kim;
	delete pam;

	return 0;
}
