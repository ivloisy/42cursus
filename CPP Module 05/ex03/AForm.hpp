/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:05:35 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/29 19:39:14 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

# include <iostream>

class	Bureaucrat;

class	AForm
{
	private:
		AForm();
		std::string const	_name;
		bool				_signed;
		int const			_signGrade;
		int const			_execGrade;

	public:
		virtual ~AForm();
		AForm(AForm const &src);
		AForm				&operator=(AForm const &rhs);
		AForm(std::string name, int const signGrade, int const execGrade);
		std::string	const	getName() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		void				beSigned(Bureaucrat const &src);
	
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return "'s grade is too high.";
				}
		};
	
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return "'s grade is too low.";
				}
		};

		class	NotSignedExeption : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return " is not signed.";
				}
		};

		virtual std::string	getTarget() const = 0;
		void				execute(Bureaucrat const &executor) const;
		virtual void		action() const = 0;
};

std::ostream	&operator<<(std::ostream &o, AForm const &rhs);

#endif
