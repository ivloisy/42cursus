/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:01:41 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/11 19:37:02 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span() : _N(0)
{
	std::cout << "\033[2;37m" << "Span constructor called" << "\033[0m" << std::endl;
	return ;
}

Span::Span( const Span & src )
{
	*this = src;
	std::cout << "\033[2;37m" << "Span copy constructor called" << "\033[0m" << std::endl;
	return ;
}

Span::Span( unsigned int N ) : _N(N) 
{
	std::cout << "\033[2;37m" << "Span constructor called" << "\033[0m" << std::endl;
	return ;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
	std::cout << "\033[2;37m" << "Span destructor called" << "\033[0m" << std::endl;
	return ;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
	{
		this->_N = rhs.getN();
		this->_span.clear();
		this->_span = rhs.getSpan();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Span const & rhs )
{
	for (int i = 0; i < static_cast<int>(rhs.getSpan().size()); i++)
		o << rhs.getSpan()[i] << " ";
	o << "\n";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Span::addNumber( int n )
{
	if ( _span.size() < this->_N)
		_span.push_back(n);
	else
		throw SpanFullException();
	return ;
}

void	Span::addRange(std::vector<int>::iterator b, std::vector<int>::iterator e)
{
	if (distance(b, e) > this->getN())
		throw tooBigRangeException();
	_span.insert( _span.begin(), b, e );
}

int	Span::shortestSpan() const
{
	if (this->_span.size() <= 1)
		throw NotEnoughException();
	std::vector<int>	tmp;
	for (unsigned long i = 0; i < this->_span.size(); i++)
		tmp.push_back(this->_span[i]);
	std::sort(tmp.begin(), tmp.end());
	int	min = INT_MAX;
	for (std::vector<int>::iterator it = tmp.begin() + 1; it != tmp.end(); ++it)
	{
		if (*it - *(it - 1) < min)
			min = *it - *(it - 1);
	}
/* 	if (this->_span.size() <= 1)
		throw NotEnoughException();
	int	min = INT_MAX;
	int	i = 0;
	int j;
	while (i < static_cast<int>(_span.size()))
	{
		j = i + 1;
		while (j  < static_cast<int>(_span.size()))
		{
			if (abs(_span[i] - _span[j]) < min)
				min = abs(_span[i] - _span[j]);
			j++;
		}
		i++;
	} */
	return min;
}

int	Span::longestSpan() const
{
	if (this->_span.size() <= 1)
		throw NotEnoughException();
	return (*std::max_element(_span.begin(), _span.end()) - *std::min_element(_span.begin(), _span.end()));
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

unsigned int	Span::getN() const
{
	return this->_N;
}

std::vector<int>	Span::getSpan() const
{
	return this->_span;
}


/* ************************************************************************** */