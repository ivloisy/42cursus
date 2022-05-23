/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:48:03 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/20 19:30:10 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:

	public:
		FragTrap(void);
		~FragTrap();
		FragTrap(FragTrap const &src);
		FragTrap	&operator=(FragTrap const &rhs);
		FragTrap(std::string name);
		void		attack(std::string const &target);
		void		highFivesGuys(void);
};

#endif
