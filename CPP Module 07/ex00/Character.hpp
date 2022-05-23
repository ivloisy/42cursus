/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 06:27:01 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/05 08:45:39 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>

class Character
{
	public:
		Character();
		Character( Character const & src );
		Character( std::string name, int age);
		~Character();

		Character	& operator=( Character const & rhs );
		bool		operator<( Character const & rhs ) const;
		bool		operator>( Character const & rhs ) const;

		std::string	getName() const;
		int			getAge() const;

	private:
		std::string	_name;
		int			_age;
};

std::ostream &			operator<<( std::ostream & o, Character const & i );

#endif /* ******************************************************* CHARACTER_H */