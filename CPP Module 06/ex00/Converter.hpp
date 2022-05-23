/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 02:38:35 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/07 12:45:03 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Converter_HPP
# define Converter_HPP

# include <iostream>
# include <climits>
# include <cmath>
# include <iomanip>

class	Converter
{
	private:
		Converter();
		Converter(Converter const &src);

		std::string const	_str;
		std::string			_type;
		char				_char;
		int					_int;
		float				_float;
		double				_double;

	public:
		Converter(std::string const str);
		~Converter();

		Converter	&operator=(Converter const &rhs);

		std::string	getStr() const;
		std::string	getType() const;
		char		getChar() const;
		int			getInt() const;
		float		getFloat() const;
		double		getDouble() const;
		void		detectType();
		bool		isInt();
		bool		isFloat();

		class	ImpossibleException : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return "impossible";
				}
		};

		class	NonDisplayableException : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return "Non displayable";
				}
		};

		char		toChar();
		int			toInt();
		float		toFloat();
		double		toDouble();
		
};

std::ostream	&operator<<(std::ostream & o, Converter &rhs);

#endif
