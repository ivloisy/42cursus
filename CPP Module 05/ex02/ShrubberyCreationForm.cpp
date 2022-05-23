/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:27:46 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/01 22:48:39 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Target")
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src)
{
	*this = src;
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
		this->_target = rhs.getTarget();
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm with target " << target << " constructor called" << std::endl;
	return ;
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

void	ShrubberyCreationForm::action() const
{
	std::ofstream	f;

	f.open((this->_target + "_shrubbery").c_str());
	if (!f.good())
		throw ErrorFileExecption();
	f << "            &&& &&  & &&" << std::endl;
	f << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
	f << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
	f << "   &() &\\/&|()|/&\\/ % & ()" << std::endl;
	f << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
	f << "&&   && & &| &| /& & % ()& /&&" << std::endl;
	f << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
	f << "     &&     \\|||" << std::endl;
	f << "             |||" << std::endl;
	f << "             |||" << std::endl;
	f << "             |||" << std::endl;
	f << "       , -=-~  .-^- _" << std::endl;
	f << "             `" << std::endl;
	f.close();
	return ;
}

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm const &rhs)
{
	o << rhs.getName() << ", form grade " << rhs.getSignGrade() << " requiered to sign it and grade " << rhs.getExecGrade() << " requiered to execute it and has for target " << rhs.getTarget() << ", is ";
	if (rhs.getSigned() == 0)
		o << "not ";
	o << "signed.";
	return o;
}
