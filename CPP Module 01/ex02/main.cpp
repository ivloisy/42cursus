/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 23:38:18 by ivloisy           #+#    #+#             */
/*   Updated: 2022/01/11 19:06:21 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "Address of the string :\t\t" << &string << std::endl;
	std::cout << "Address by the pointer :\t" << stringPTR << std::endl;
	std::cout << "Address by the reference :\t" << &stringREF << std::endl;
	std::cout << "The string by the pointer :\t" << *stringPTR << std::endl;
	std::cout << "The string by the reference :\t" << stringREF << std::endl;
}
