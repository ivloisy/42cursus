/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 00:17:21 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/10 22:55:07 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <sstream>

class Zombie
{
	private:
		std::string	_name;
		
	public:
		Zombie(void);
		Zombie(std::string zombieName);
		~Zombie(void);
		void	setName(std::string name, int i);
		void	announce(void) const;
};

Zombie	*zombieHorde(int N, std::string name);

#endif
