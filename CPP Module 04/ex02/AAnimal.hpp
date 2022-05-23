/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:48:26 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/23 18:11:37 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
	private:

	protected:
		std::string	type;

	public:
		AAnimal();
		virtual ~AAnimal();
		AAnimal(AAnimal const &src);
		AAnimal			&operator=(AAnimal const &rhs);
		std::string		getType() const;
		virtual void	makeSound() const = 0;
};

#endif
