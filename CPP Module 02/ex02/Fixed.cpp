/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:45:13 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/14 23:54:49 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_n = 0;
	return ;
}

Fixed::~Fixed()
{
	return ;
}

Fixed::Fixed(Fixed const &src)
{
	*this = src;
	return ;
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
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
	return ;
}

Fixed::Fixed(float const f) : _n((int)roundf(f * (1 << _b)))
{
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

bool	Fixed::operator>(Fixed const &rhs) const
{
	return this->getRawBits() > rhs.getRawBits();
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	return this->getRawBits() < rhs.getRawBits();
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	return this->getRawBits() >= rhs.getRawBits();
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	return this->getRawBits() <= rhs.getRawBits();
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	return this->getRawBits() == rhs.getRawBits();
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	return this->getRawBits() != rhs.getRawBits();
}

Fixed	Fixed::operator+(Fixed const &rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(Fixed const &rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(Fixed const &rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed	&Fixed::operator++(void)
{
	this->_n++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	this->_n++;
	return tmp;
}

Fixed	&Fixed::operator--(void)
{
	this->_n--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	this->_n--;
	return tmp;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;	
}
