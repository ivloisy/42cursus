/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 02:30:48 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/04 22:32:33 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# include <iostream>
# include <string>
# include <cstdlib>
# include <cstdio>
# include <cstring>

class PhoneBook
{
	private:
		Contact	_contact[8];
		int		_total;
		bool	_cmd_add(void);
		bool	_cmd_search(int n);

	public:
		PhoneBook(void);
		~PhoneBook();
		bool		getCommand(void);
		int			chooseIndex(void);
		int			chooseContact(void);
		std::string	printInfo(std::string s) const;
		void		printContact(void);
};

#endif
