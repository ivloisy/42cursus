/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:11:44 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/11 12:35:56 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template< typename T >
typename T::iterator	easyfind( T & t, int n )
{
	typename T::iterator	it;
	it = std::find( t.begin(), t.end(), n );
	if ( it == t.end() )
		throw NotFoundException();
	return it;
}
