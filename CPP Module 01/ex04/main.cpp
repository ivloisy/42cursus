/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 23:38:18 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/12 03:21:28 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string	replace_line(std::string line, std::string s1, std::string s2)
{
	std::string	tmp = line;
	std::string	tmp2 = line;
	size_t		pos;
	int			x = 0;

	while ((pos = tmp.find(s1)) != std::string::npos)
	{
		tmp.erase(pos, s1.length());
		x++;
	}
	size_t		tab[x];
 	int			y = 0;
	while ((pos = tmp2.find(s1)) != std::string::npos && y < x)
	{
		tab[y] = pos;
		tmp2.erase(pos, s1.length());
		y++;
	}
	for (int i = x - 1; i > -1; i--)
		tmp.insert(tab[i], s2);
	return (tmp);
}

int	main(int ac, char **av)
{
	if (ac != 4 || !av[2][0] || !av[3][0])
	{
		std::cerr << "Error : Invalid argument" << std::endl;
		return (1);
	}
	std::ifstream	ifs(av[1]);
	if (!ifs.good())
	{
		std::cerr << "Error : No such file" << std::endl;
		return (1);
	}
	std::string		filename = av[1];
	filename = filename + ".replace";
	std::string		s1 = av[2];
	std::string		s2 = av[3];
	std::ofstream	ofs(filename.c_str());
	std::string		line;
	std::string		tmp;
	while (getline(ifs, line))
	{
		tmp = replace_line(line, s1, s2);
		ofs << tmp << std::endl;
	}
	ofs.close();
	ifs.close();
	return (0);
}
