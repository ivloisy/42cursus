/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 02:29:35 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/05 16:37:23 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "***************** PHONEBOOK *****************" << std::endl;
	this->_total = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "****************** GOODBYE ******************" << std::endl;
	return ;
}

bool	PhoneBook::_cmd_add(void)
{
	std::string	info[5];
	std::string	field[5] = {
		"First name : ",
		"Last name : ",
		"Nickname : ",
		"Phone number : ",
		"Darkest secret : "
	};
	int			index;
	
	index = this->_total;
	if (this->_total == 8)
	{
		std::cout << "\nThe PhoneBook is full." << std::endl;
		index = this->chooseIndex();
	}
	else
		this->_total++;
	if (index != -1)
	{
		for (int i = 0; i < 5; i++)
		{
			std::cout << field[i];
			if (!std::getline (std::cin, info[i]))
			{
				std::cerr << "\nSorry, an error occured.\n" << std::endl;
				return (false);
			}
		}
		this->_contact[index].setContact(info);
		std::cout << std::endl << this->printInfo(info[0])
		<< " has been added to the PhoneBook.\n" << std::endl;
	}
	return (true);
}

bool	PhoneBook::_cmd_search(int n)
{
	if (!this->_total)
		std::cerr << "\nThe PhoneBook is empty.\n" << std::endl;
	else
	{
		std::cout << "\n|     index|first name| last name|  nickname|"
		<< std::endl;
		std::cout << "|----------|----------|----------|----------|"
		<< std::endl;
		for (int i = 0; i < this->_total; i++)
		{
			std::cout << "|         " << i + 1
			<< "|" << this->printInfo(this->_contact[i].getInfo(0))
			<< "|" << this->printInfo(this->_contact[i].getInfo(1))
			<< "|" << this->printInfo(this->_contact[i].getInfo(2))
			<< "|" << std::endl;
		}
		std::cout << std::endl;
	}
	if (n)
		this->printContact();
	return (true);
}

bool	PhoneBook::getCommand(void)
{
	std::string	command;
	
	std::cout << "Please, enter a command (ADD, SEARCH or EXIT)" << std::endl;
	std::cout << "Command : ";
	if (!std::getline (std::cin, command))
	{
		std::cerr << "\nSorry, an error occured.\n" << std::endl;
		return (false);
	}
	if (command == "ADD")
		return (this->_cmd_add());
	else if (command == "SEARCH")
		return (this->_cmd_search(1));
	else if (command == "EXIT")
		return (false);
	return (true);
}

int	PhoneBook::chooseIndex(void)
{
	int		i;
	int		r;
	char	s[256];
	
	r = 0;
	while (!r)
	{
		this->_cmd_search(0);
		std::cout << "Choose an index to replace the contact.\n"
		<< "If 0 is entered, the addition is canceled.\n" << "Index : ";
		fgets (s, 256, stdin);
		if ((!strncmp(s, "1", 1) || !strncmp(s, "2", 1) || !strncmp(s, "3", 1)
				|| !strncmp(s, "4", 1) || !strncmp(s, "5", 1)
				|| !strncmp(s, "6", 1) || !strncmp(s, "7", 1)
				|| !strncmp(s, "8", 1) || !strncmp(s, "0", 1))
				&& atoi(s) < 9 && atoi(s) >= 0 && !isprint(s[1]))
		{
			r = 1;
			i = atoi(s) - 1;
		}
		else
			std::cerr << "\nIt is not a good index." << std::endl;
	}
	return (i);
}

int	PhoneBook::chooseContact(void)
{
	int		i;
	int		r;
	char	s[256];
	
	r = 0;
	while (!r)
	{
		std::cout << "Choose an index to display the informations\n"
		<< "of the contact.\n" << "Index : ";
		fgets (s, 256, stdin);
		if ((!strncmp(s, "1", 1) || !strncmp(s, "2", 1) || !strncmp(s, "3", 1)
				|| !strncmp(s, "4", 1) || !strncmp(s, "5", 1)
				|| !strncmp(s, "6", 1) || !strncmp(s, "7", 1)
				|| !strncmp(s, "8", 1)) && !isprint(s[1])
				&& (atoi(s) > 0 && atoi(s) <= this->_total))
		{
			r = 1;
			i = atoi(s) - 1;
		}
		else
		{
			std::cerr << "\nIt is not a good index." << std::endl;
			this->_cmd_search(0);
		}
	}
	return (i);
}

std::string	PhoneBook::printInfo(std::string s) const
{
	if (s.size() < 10)
	{
		while (s.size() < 10)
		{
			s = s.insert(0, " ");
		}
	}
	else if (s.size() > 10)
	{
		s = s.insert(9, ".");
		s = s.substr(0, 10);
	}
	return (s);
}

void	PhoneBook::printContact(void)
{
	int		index;
	
	index = this->chooseContact();
	std::cout << "\nFirst name :\t\t" << this->_contact[index].getInfo(0)
	<< std::endl;
	std::cout << "Last name :\t\t" << this->_contact[index].getInfo(1)
	<< std::endl;
	std::cout << "Nickname :\t\t" << this->_contact[index].getInfo(2)
	<< std::endl; 
	std::cout << "Phone number :\t\t" << this->_contact[index].getInfo(3)
	<< std::endl; 
	std::cout << "Darkest secret :\t" << this->_contact[index].getInfo(4)
	<< std::endl << std::endl; 
}
