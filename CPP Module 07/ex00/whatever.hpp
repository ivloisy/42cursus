/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 04:19:37 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/05 05:15:53 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template<typename T>
void	swap( T & a, T & b)
{
	T	tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T const	min( T const & a, T const & b )
{
	return ( a < b ? a : b);
}

template<typename T>
T const	max( T const & a, T const & b )
{
	return ( a > b ? a : b);
}

#endif
