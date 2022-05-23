/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:05:35 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/29 14:56:04 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_signGrade;
		int const			_execGrade;

	public:
		Form();
		~Form();
		Form(Form const &src);
		Form			&operator=(Form const &rhs);
		Form(std::string name, int const signGrade, int const execGrade);
		std::string	const	getName() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		void				beSigned(Bureaucrat const &src);
	
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "'s grade is too high.";
				}
		};
	
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "'s grade is too low.";
				}
		};
};

std::ostream	&operator<<(std::ostream &o, Form const &rhs);

#endif
