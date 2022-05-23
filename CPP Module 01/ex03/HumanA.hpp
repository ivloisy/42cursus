/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 01:30:08 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/11 19:06:06 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class	HumanA
{
	private:
		std::string	_name;
		Weapon		&_weaponRef;
		
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		void	attack() const;
};

#endif
