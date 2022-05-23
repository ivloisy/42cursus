/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 03:30:32 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/07 03:45:16 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Converter::Converter()
{
	std::cout << "\033[2;37m" << "Converter constructor called" << "\033[0m" << std::endl;
	return ;
}

Converter::Converter(const Converter &src)
{
	*this = src;
	std::cout << "\033[2;37m" << "Converter copy constructor called" << "\033[0m" << std::endl;
	return ;
}

Converter::Converter(std::string str) : _str(str), _char(0), _int(0), _float(0), _double(0)
{
	std::cout << "\033[2;37m" << "Converter constructor called" << "\033[0m" << std::endl;
	this->detectType();
	return ;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Converter::~Converter()
{
	std::cout << "\033[2;37m" << "Converter destructor called" << "\033[0m" << std::endl;
	return ;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Converter	&Converter::operator=(Converter const &rhs)
{
	(void)rhs;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Converter &rhs)
{
	o << "char: ";
	try
	{
		char	c = rhs.toChar();
		o << "'" << c << "'" << std::endl;
	}
	catch(const std::exception& e)
	{
		o << e.what() << std::endl;
	}

	o << "int: ";
	try
	{
		o << rhs.toInt() << std::endl;
	}
	catch(const std::exception& e)
	{
		o << e.what() << std::endl;
	}
	
	o << "float: ";
	try
	{
		o << std::fixed;
		o << std::setprecision(1);
		o << rhs.toFloat();
		o << "f" << std::endl;
	}
	catch(const std::exception& e)
	{
		o << e.what() << std::endl;
	}

	o << "double: ";
	try
	{
		o << std::fixed;
		o << std::setprecision(1);
		o << rhs.toDouble();
		o << std::endl;
	}
	catch(const std::exception& e)
	{
		o << e.what() << std::endl;
	}

	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Converter::detectType()
{
	if (this->getStr().length() == 1 && !isdigit(_str[0]))
	{
		this->_type = "char";
		this->_char = _str[0];
		this->_int = static_cast<int>(_char);
		this->_float = static_cast<float>(this->_char);
		this->_double = static_cast<double>(this->_char);
	}
	else if (isInt())
		this->_type = "int";
	else if (!_str.compare("-inff") || !_str.compare("+inff") || !_str.compare("nanf"))
	{
		this->_type = "float";
		this->_float = static_cast<float>(atof(_str.c_str()));
		this->_double = static_cast<double>(this->_float);
	}
	else if (!_str.compare("-inf") || !_str.compare("+inf") || !_str.compare("nan"))
	{
		this->_type = "double";
		this->_double = atof(_str.c_str());
	}
	else if (isFloat())
		return ;
	else
		this->_type = "wrong";
	return ;
}

bool	Converter::isInt()
{
	long	x;
	int		i = 0;
	
	if (_str[i] && (_str[i] == '+' || _str[i] == '-'))
		i++;
	while (_str[i] && isdigit(_str[i]))
		i++;
	if (i == static_cast<int>(_str.length()))
	{
		x = atol(_str.c_str());
		if (x >= INT_MIN && x <= INT_MAX)
		{
			this->_int = static_cast<int>(x);
			this->_float = static_cast<float>(this->_int);
			this->_double = static_cast<double>(this->_int);
			return true;
		}
	}
	return false;
}

bool	Converter::isFloat()
{
	int		i = 0;

	if (_str[i] && (_str[i] == '+' || _str[i] == '-'))
		i++;
	while (_str[i] && isdigit(_str[i]))
		i++;
	if (_str[i] && _str[i] == '.' && _str[i + 1] && isdigit(_str[i + 1]))
		i++;
	else
		return false;
	while (_str[i] && isdigit(_str[i]))
		i++;
	if (_str[i] && _str[i] == 'f' && _str[i + 1] == '\0')
	{
		this->_type = "float";
		this->_float = static_cast<float>(atof(_str.c_str()));
		this->_double = static_cast<double>(this->_float);
		return true;
	}
	else if (_str[i] == '\0')
	{
		this->_type = "double";
		this->_double = atof(_str.c_str());
		return true;
	}
	return false;
}

char	Converter::toChar()
{
	if (!this->getType().compare("wrong"))
		throw ImpossibleException();
	if (!this->getType().compare("int") || !this->getType().compare("float") || !this->getType().compare("double"))
	{
		if (this->getDouble() < 0 || this->getDouble() > 127 || isinf(this->getDouble()) || isnan(this->getDouble()))
			throw ImpossibleException();
		this->_char = static_cast<char>(this->getDouble());
		if (!isprint(this->getChar()))
			throw NonDisplayableException();
	}
	return this->_char;
}

int	Converter::toInt()
{
	if (!this->getType().compare("wrong"))
		throw ImpossibleException();
	if (!this->getType().compare("float") || !this->getType().compare("double"))
	{
		if (this->getDouble() < INT_MIN || this->getDouble() > INT_MAX || isinf(this->getDouble()) || isnan(this->getDouble()))
			throw ImpossibleException();
		this->_int = static_cast<int>(this->getDouble());
	}
	return this->_int;
}

float	Converter::toFloat()
{
	if (!this->getType().compare("wrong"))
		throw ImpossibleException();
	if (!this->getType().compare("double"))
		this->_float = static_cast<float>(this->getDouble());
	return this->_float;
}

double	Converter::toDouble()
{
	if (!this->getType().compare("wrong"))
		throw ImpossibleException();
	return this->_double;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Converter::getStr() const
{
	return this->_str;
}

std::string	Converter::getType() const
{
	return this->_type;
}

char		Converter::getChar() const
{
	return this->_char;
}

int			Converter::getInt() const
{
	return this->_int;
}

float		Converter::getFloat() const
{
	return this->_float;
}

double		Converter::getDouble() const
{
	return this->_double;
}

/* ************************************************************************** */