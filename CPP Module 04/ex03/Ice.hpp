/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:00:23 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/25 19:08:29 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	private:

	public:
		Ice();
		virtual ~Ice();
		Ice(Ice const &src);
		Ice					&operator=(Ice const &rhs);
		virtual AMateria	*clone() const;
		virtual void		use(ICharacter &target);
};

#endif
