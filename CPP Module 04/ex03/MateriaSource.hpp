/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 03:39:27 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/26 11:16:31 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_slot[4];

	public:
		MateriaSource();
		virtual ~MateriaSource();
		MateriaSource(MateriaSource const &src);
		MateriaSource	&operator=(MateriaSource const &rhs);
		void			learnMateria(AMateria *);
		AMateria		*createMateria(std::string const &type);
};

#endif
