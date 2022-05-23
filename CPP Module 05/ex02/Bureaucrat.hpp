/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 03:01:02 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/01 19:54:51 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

# include "AForm.hpp"

class	AForm;

class	Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;

	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &src);
		Bureaucrat			&operator=(Bureaucrat const &rhs);
		Bureaucrat(std::string name, int grade);
		std::string	const	getName() const;
		int					getGrade() const;
		void				upGrade();
		void				downGrade();
		void				signForm(AForm &src) const;
		void				executeForm(AForm const &form) const;

		
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "the grade is too high.";
				}
		};
		
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "the grade is too low.";
				}
		};
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
