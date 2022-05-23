/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:07:26 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/01 22:43:32 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("AForm"), _signed(false), _signGrade(150), _execGrade(150)
{
	std::cout << "AForm constructor called" << std::endl;
	return ;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
	return ;
}

AForm::AForm(AForm const &src) : _name(src.getName()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade())
{
	*this = src;
	std::cout << "AForm copy constructor called" << std::endl;
	return ;
}

AForm	&AForm::operator=(AForm const &rhs)
{
	if (this != &rhs)
		this->_signed = rhs._signed;
	return *this;
}

AForm::AForm(std::string name, int const signGrade, int const execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	std::cout << "AForm named " << this->getName() << " constructor called" << std::endl;
	return ;
}

std::string	const	AForm::getName() const
{
	return this->_name;
}

bool	AForm::getSigned() const
{
	return this->_signed;
}

int	AForm::getSignGrade() const
{
	return this->_signGrade;
}

int	AForm::getExecGrade() const
{
	return this->_execGrade;
}

void	AForm::beSigned(Bureaucrat const &src)
{
	if (src.getGrade() > this->_signGrade)
		throw GradeTooHighException();
	this->_signed = true;
	return ;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (this->_signed == false)
		throw NotSignedExeption();
	if (this->getExecGrade() < executor.getGrade())
		throw GradeTooHighException();
	this->action();
}

std::ostream	&operator<<(std::ostream &o, AForm const &rhs)
{
	o << rhs.getName() << ", form grade " << rhs.getSignGrade() << " requiered to sign it and grade " << rhs.getExecGrade() << " requiered to execute it, is ";
	if (rhs.getSigned() == 0)
		o << "not ";
	o << "signed.";
	return o;
}
