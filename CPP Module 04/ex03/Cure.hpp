/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:00:23 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/25 15:10:35 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	private:

	public:
		Cure();
		virtual ~Cure();
		Cure(Cure const &src);
		Cure				&operator=(Cure const &rhs);
		virtual AMateria	*clone() const;
		virtual void		use(ICharacter &target);
};

#endif
