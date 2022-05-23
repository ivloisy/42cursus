/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:07:26 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/01 22:44:05 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Form"), _signed(false), _signGrade(150), _execGrade(150)
{
	std::cout << "Form constructor called" << std::endl;
	return ;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
	return ;
}

Form::Form(Form const &src) : _name(src.getName()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade())
{
	*this = src;
	std::cout << "Form copy constructor called" << std::endl;
	return ;
}

Form	&Form::operator=(Form const &rhs)
{
	if (this != &rhs)
		this->_signed = rhs._signed;
	return *this;
}

Form::Form(std::string name, int const signGrade, int const execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	std::cout << "Form named " << this->getName() << " constructor called" << std::endl;
	return ;
}

std::string	const	Form::getName() const
{
	return this->_name;
}

bool	Form::getSigned() const
{
	return this->_signed;
}

int	Form::getSignGrade() const
{
	return this->_signGrade;
}

int	Form::getExecGrade() const
{
	return this->_execGrade;
}

void	Form::beSigned(Bureaucrat const &src)
{
	if (src.getGrade() > this->_signGrade)
		throw GradeTooHighException();
	this->_signed = true;
	return ;
}

std::ostream	&operator<<(std::ostream &o, Form const &rhs)
{
	o << rhs.getName() << ", form grade " << rhs.getSignGrade() << " requiered to sign it and grade " << rhs.getExecGrade() << " requiered to execute it, is ";
	if (rhs.getSigned() == 0)
		o << "not ";
	o << "signed.";
	return o;
}
