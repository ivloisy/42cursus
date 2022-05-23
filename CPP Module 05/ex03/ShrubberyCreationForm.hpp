/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:21:29 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/01 00:23:34 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

# include <fstream>

class	ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &src);

	public:
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rhs);
		ShrubberyCreationForm(std::string const target);
		std::string				getTarget() const;
		void					action() const;

		class	ErrorFileExecption : std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return "'s file cannot be opened.";
				}
		};
};

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm const &rhs);

#endif
