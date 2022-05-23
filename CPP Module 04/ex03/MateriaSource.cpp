/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 03:47:44 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/26 11:47:51 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_slot[i] = NULL;
	std::cout << "MateriaSource constructor called" << std::endl;
	return ;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (_slot[i] != NULL)
			delete _slot[i];
	std::cout << "MateriaSource destructor called" << std::endl;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
	*this = src;
	std::cout << "MateriaSource copy constructor called" << std::endl;
	return ;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (rhs._slot[i])
				_slot[i] = rhs._slot[i]->clone();
			else
				_slot[i] = NULL;
		}
	}
	return *this;
}

void    MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; i++)
	{
		if (_slot[i] == NULL)
		{
			_slot[i] = m;
			std::cout << "MateriaSource learns " << m->getType() << std::endl;
			return ;
		}
	}
	delete m;
	std::cout << "MateriaSource's inventory is full" << std::endl;
    return ;
}

AMateria    *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_slot[i] != NULL && _slot[i]->getType() == type)
        {
			std::cout << "MateriaSource creates " << type << std::endl;
			return (_slot[i]->clone());
        }
	}
    std::cout << "MateriaSource has not learn " << type << std::endl;
	return NULL;
}
