/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:08:55 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/25 13:08:25 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain	*brain;

	public:
		Cat();
		virtual ~Cat();
		Cat(Cat const &src);
		Cat				&operator=(Cat const &rhs);
		virtual void	makeSound() const;
		Brain			*getBrain() const;
};

#endif
