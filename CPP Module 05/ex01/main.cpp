/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 04:20:44 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/01 19:41:46 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat	*bob = NULL;
	Bureaucrat	*jim = NULL;
	Bureaucrat	*kim = NULL;
	Bureaucrat	*pam = NULL;
	Form		*order = NULL;
	Form		*order2 = NULL;
	Form		*order3 = NULL;

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
		order = new Form("Order", 15, 50);
		std::cout << *order << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << "Order" << e.what() << std::endl;
	}

	try
	{
		order2 = new Form("Order2", 0, 50);
		std::cout << *order2 << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << "Order2" << e.what() << std::endl;
	}

	try
	{
		order3 = new Form("Order3", 1, 250);
		std::cout << *order2 << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << "Order3" << e.what() << std::endl;
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

	jim->signForm(*order);
	bob->signForm(*order);

	std::cout << *order << std::endl;

	delete bob;
	delete jim;
	delete kim;
	delete pam;
	delete order;
	delete order2;

	return 0;
}
