/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 01:51:33 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/04 15:13:53 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::setContact(std::string info[5])
{
	this->_first_name = info[0];
	this->_last_name = info[1];
	this->_nickname = info[2];
	this->_phone_number = info[3];
	this->_darkest_secret = info[4];
	return ;
}

std::string	Contact::getInfo(int n) const
{
	if (n == 0)
		return (this->_first_name);
	else if (n == 1)
		return (this->_last_name);
	else if (n == 2)
		return (this->_nickname);
	else if (n == 3)
		return (this->_phone_number);
	else if (n == 4)
		return (this->_darkest_secret);
	else
		return (NULL);
}
