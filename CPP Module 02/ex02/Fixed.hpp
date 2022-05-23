/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:05:54 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/14 23:35:43 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_n;
		static int const	_b = 8;

	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const &src);
		Fixed				&operator=(Fixed const &rhs);
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		Fixed(int const n);
		Fixed(float const f);
		float				toFloat(void) const;
		int					toInt(void) const;
		bool				operator>(Fixed const &rhs) const;
		bool				operator<(Fixed const &rhs) const;
		bool				operator>=(Fixed const &rhs) const;
		bool				operator<=(Fixed const &rhs) const;
		bool				operator==(Fixed const &rhs) const;
		bool				operator!=(Fixed const &rhs) const;
		Fixed				operator+(Fixed const &rhs) const;
		Fixed				operator-(Fixed const &rhs) const;
		Fixed				operator*(Fixed const &rhs) const;
		Fixed				operator/(Fixed const &rhs) const;
		Fixed				&operator++(void);
		Fixed				operator++(int);
		Fixed				&operator--(void);
		Fixed				operator--(int);
		static Fixed		&min(Fixed &a, Fixed &b);
		const static Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		const static Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs);

#endif
