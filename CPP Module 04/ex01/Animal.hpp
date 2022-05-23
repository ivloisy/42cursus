/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:48:26 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/26 18:09:23 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	private:

	protected:
		std::string	type;

	public:
		Animal();
		virtual ~Animal();
		Animal(Animal const &src);
		Animal			&operator=(Animal const &rhs);
		std::string		getType() const;
		virtual void	makeSound() const;
};

#endif
