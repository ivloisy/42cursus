/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:21:29 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/01 00:54:18 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

# include <ctime>
# include <cstdlib>

class	RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;
		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &src);

	public:
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &rhs);
		RobotomyRequestForm(std::string const target);
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

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm const &rhs);

#endif
