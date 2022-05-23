/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:27:46 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/01 22:48:29 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Target")
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src)
{
	*this = src;
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
		this->_target = rhs.getTarget();
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm with target " << target << " constructor called" << std::endl;
	return ;
}

std::string	RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void	RobotomyRequestForm::action() const
{
	bool	robotomized;

	std::cout << "* BrzzzRzzzRzzz... *" << std::endl;
	robotomized = rand() % 2;
	if (robotomized)
		std::cout << this->getTarget() << " is robotomized" << std::endl;
	else
		std::cout << this->getTarget() << " is not robotomized" << std::endl;
	return ;
}

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm const &rhs)
{
	o << rhs.getName() << ", form grade " << rhs.getSignGrade() << " requiered to sign it and grade " << rhs.getExecGrade() << " requiered to execute it and has for target " << rhs.getTarget() << ", is ";
	if (rhs.getSigned() == 0)
		o << "not ";
	o << "signed.";
	return o;
}
