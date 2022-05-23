/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 03:12:26 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/01 18:48:50 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(150)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	return ;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src.getName())
{
	*this = src;
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	return ;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
		this->_grade = rhs.getGrade();
	return *this;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
	std::cout << "Bureaucrat named " << this->getName() << " constructor called" << std::endl;
	return ;
}

std::string	const	Bureaucrat::getName() const
{
	return this->_name;
}

int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

void	Bureaucrat::upGrade()
{
	if (this->_grade > 1)
	{
		std::cout << *this << ", has been upraded at the grade " << this->getGrade() - 1 << std::endl;
		this->_grade--;
	}
	else
		throw GradeTooHighException();
	return ;
}

void	Bureaucrat::downGrade()
{
	if (this->_grade < 150)
	{
		std::cout << *this << ", has been dowgraded at the grade " << this->getGrade() + 1 << std::endl;
		this->_grade++;
	}
	else
		throw GradeTooLowException();
	return ;
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}
