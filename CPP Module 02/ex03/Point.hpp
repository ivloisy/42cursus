/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 00:44:42 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/18 19:23:55 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	x;
		Fixed const	y;

	public:
		Point(void);
		~Point();
		Point(Point const &src);
		Point(Fixed const a, Fixed const b);
		Point	&operator=(Point const &rhs);
		float	getX(void) const;
		float	getY(void) const;
};

std::ostream	&operator<<(std::ostream &o, const Point &rhs);

#endif
