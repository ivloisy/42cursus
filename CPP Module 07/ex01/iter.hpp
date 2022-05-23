/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 05:30:20 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/10 16:25:37 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <iomanip>

template<typename T>
void	iter( T const * tab, int size, void (* f)( T const & ) )
{
	if ( !f || tab == NULL)
		return ;
	for ( int i = 0; i < size; i++)
		f(tab[i]);
}

template<typename T>
void	printElem( T const & elem)
{
	std::cout << elem << std::endl;
	return ;
}

#endif