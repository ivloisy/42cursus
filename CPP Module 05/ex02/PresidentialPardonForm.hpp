/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:21:29 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/01 01:29:10 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;
		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &src);

	public:
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm	&operator=(PresidentialPardonForm const &rhs);
		PresidentialPardonForm(std::string const target);
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

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm const &rhs);

#endif
