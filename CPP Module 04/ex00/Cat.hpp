/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:08:55 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/23 18:11:51 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	private:

	public:
		Cat();
		virtual ~Cat();
		Cat(Cat const &src);
		Cat				&operator=(Cat const &rhs);
		virtual void	makeSound() const;
};

#endif
