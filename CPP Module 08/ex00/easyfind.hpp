/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:11:47 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/11 12:49:46 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <algorithm>

class	NotFoundException : public std::exception
{
	public:
		virtual const char	* what() const throw()
		{
			return "not found";
		}
};

# include "easyfind.tpp"

#endif /* ******************************************************** EASYFIND_H */
