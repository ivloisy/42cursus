/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:58:57 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/11 18:46:49 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iomanip>

int	main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(-3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(111);	
	try
	{
		sp.addNumber(11);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "sp: " << sp << std::endl;
	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

	Span sp2 = Span(6);
	try
	{
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	sp2.addNumber(2);
	try
	{
		std::cout << sp2.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Span sp3 = Span(12000);
	std::vector<int>	vec;
	for (int i = 0; i < 12000; i++)
		vec.push_back(i);
	std::vector<int>	vec2;
	for (int i = 0; i < 12001; i++)
		vec2.push_back(i);
	try
	{
		sp3.addRange(vec2.begin(), vec2.end());
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		sp3.addRange(vec.begin(), vec.end());
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "sp3: " << sp3 << std::endl;
	std::cout << "Shortest Span: " << sp3.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp3.longestSpan() << std::endl;

	return 0;
}