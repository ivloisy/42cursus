/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:08:55 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/23 18:11:46 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	private:

	public:
		Dog();
		virtual ~Dog();
		Dog(Dog const &src);
		Dog				&operator=(Dog const &rhs);
		virtual void	makeSound() const;
};

#endif
