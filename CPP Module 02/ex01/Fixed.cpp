/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:45:13 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/14 16:51:02 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_n = 0;
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		this->_n = rhs.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
	return this->_n;
}

void	Fixed::setRawBits(int const raw)
{
	this->_n = raw;
	return ;
}

Fixed::Fixed(int const n) : _n(n << _b)
{
	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed(float const f) : _n((int)roundf(f * (1 << _b)))
{
	std::cout << "Float constructor called" << std::endl;
	return ;
}

float	Fixed::toFloat(void) const
{
	return ((float)_n / (1 << _b));
}

int	Fixed::toInt(void) const
{
	return this->_n >> this->_b;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return o;
}
