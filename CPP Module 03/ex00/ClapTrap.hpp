/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:16:09 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/20 18:12:23 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PURPLE "\033[35m"
# define CYAN "\033[36m"
# define END "\033[0m"

# include <iostream>

class ClapTrap
{
	private:
		std::string		_n;
		unsigned int	_hp;
		unsigned int	_ep;
		int				_ad;

	public:
		ClapTrap(void);
		~ClapTrap();
		ClapTrap(ClapTrap const &src);
		ClapTrap	&operator=(ClapTrap const &rhs);
		ClapTrap(std::string name);
		void		attack(std::string const &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};

#endif
