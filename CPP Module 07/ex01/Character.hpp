/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 06:27:01 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/08 08:28:56 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>

class Character
{
	public:
		Character( Character const & src );
		Character( std::string name, int age);
		~Character();

		Character	& operator=( Character const & rhs );

		std::string	getName() const;
		int			getAge() const;

	private:
		Character();
		std::string	_name;
		int			_age;
};

std::ostream &			operator<<( std::ostream & o, Character const & i );

#endif /* ******************************************************* CHARACTER_H */