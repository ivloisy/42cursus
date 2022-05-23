/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:27:46 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/01 22:48:19 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Target")
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src)
{
	*this = src;
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	return ;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	if (this != &rhs)
		this->_target = rhs.getTarget();
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm with target " << target << " constructor called" << std::endl;
	return ;
}

std::string	PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

void	PresidentialPardonForm::action() const
{
	std::cout << this->getTarget() << " hes been pardoned by Zaphod Beeblebrox." << std::endl;
	return ;
}

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm const &rhs)
{
	o << rhs.getName() << ", form grade " << rhs.getSignGrade() << " requiered to sign it and grade " << rhs.getExecGrade() << " requiered to execute it and has for target " << rhs.getTarget() << ", is ";
	if (rhs.getSigned() == 0)
		o << "not ";
	o << "signed.";
	return o;
}
