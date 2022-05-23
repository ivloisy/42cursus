/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:11:25 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/11 12:49:41 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

# include <vector>
# include <set>
# include <list>

int	main()
{
	std::cout << std::endl << "\033[4;33m" << "Vector:" << "\033[0m" << std::endl;
	std::vector<int>	vec( 10, 0 );
	int	i = 0;
	std::cout << "vec: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		*it = i;
		i++;
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	try
	{
		std::cout << "42:\t";
		std::cout << *easyfind(vec, 42) << " found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "9:\t";
		std::cout << *easyfind(vec, 9) << " found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << "\033[4;33m" << "Set" << "\033[0m" << std::endl;
	std::set<int>	set;
	std::cout << "set: ";
	for ( int j = 0; j < 10; j++ )
	{
		set.insert(j);
		std::cout << j << " ";
	}
	std::cout << std::endl;
	try
	{
		std::cout << "42:\t";
		std::cout << *easyfind(set, 42) << " found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "9:\t";
		std::cout << *easyfind(set, 9) << " found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "\033[4;33m" << "List" << "\033[0m" << std::endl;
	std::list<int>	l;
	std::cout << "list: ";
	for ( int j = 0; j < 10; j++ )
	{
		l.push_back(j);
		std::cout << j << " ";
	}
	std::cout << std::endl;
	try
	{
		std::cout << "42:\t";
		std::cout << *easyfind(l, 42) << " found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "9:\t";
		std::cout << *easyfind(l, 9) << " found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
 
	return 0;
}
