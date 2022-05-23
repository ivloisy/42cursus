/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:43:59 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/25 13:34:30 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main()
{
//	AAnimal	aanimal;

	AAnimal	*meta[6];
	for (int i = 0; i < 6; i++)
	{
		if (i % 2)
			meta[i] = new Cat();
		else 
			meta[i] = new Dog();
	}
	for (int i = 0; i < 6; i++)
		meta[i]->makeSound();
	for (int i = 0; i < 6; i++)
		delete meta[i];

	srand(time(NULL));
	Cat	cat;
	{
		Cat	copy = cat;
		copy.getBrain()->printIdeas();
	}
	cat.getBrain()->printIdeas();

	Dog	dog;
	{
		Dog	copy = dog;
		copy.getBrain()->printIdeas();
	}
	dog.getBrain()->printIdeas();
	
	return 0;
}
