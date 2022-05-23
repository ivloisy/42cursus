/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 03:33:13 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/20 20:22:17 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private:

	public:
		ScavTrap(void);
		virtual ~ScavTrap();
		ScavTrap(ScavTrap const &src);
		ScavTrap	&operator=(ScavTrap const &rhs);
		ScavTrap(std::string name);
		void		attack(std::string const &target);
		void		guardGate();
};

#endif
