/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:06:24 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/26 14:08:23 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_slot[4];

	public:
		Character();
		virtual ~Character();
		Character(Character const &src);
		Character			&operator=(Character const &rhs);
		Character(std::string const name);
		void				setName(std::string const name);
		std::string const	&getName() const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);
		void				printSlots() const;
		AMateria			*getSlots(int idx) const;
};

#endif
