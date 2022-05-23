/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:22:21 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/26 18:30:55 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("caca");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(22, *bob);
    me->use(-2, *bob);
	
	Character	jim("Jim");
	tmp = src->createMateria("ice");
	jim.equip(tmp);
	tmp = src->createMateria("caca");
	jim.equip(tmp);
	tmp = src->createMateria("ice");
	jim.equip(tmp);
	tmp = src->createMateria("cure");
	jim.equip(tmp);
	tmp = src->createMateria("ice");
	jim.equip(tmp);
	tmp = src->createMateria("ice");
	jim.equip(tmp);
	{
		Character	pam(jim);
		pam.setName("Pam");
		pam.printSlots();
	}
	jim.printSlots();
	tmp = jim.getSlots(0);
	jim.unequip(0);
	jim.printSlots();
	jim.use(0, *bob);
	jim.use(3, *bob);
	delete tmp;
	
	delete bob;
	delete me;
	delete src;


	return 0;
}