/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 02:58:41 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/11 19:35:00 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	std::cout << std::endl << "\033[4;33m" << "MutantStack" << "\033[0m" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	MutantStack<int> mstack_copy = mstack;

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << "before incrementation:\t" << *it << std::endl;
	++it;
	std::cout << "after incrementation:\t" << *it << std::endl;
	--it;
	std::cout << "after decrementation:\t" << *it << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << std::endl << "\033[4;33m" << "List" << "\033[0m" << std::endl;
	std::list<int> l;

	l.push_back(5);
	l.push_back(17);

	std::cout << l.back() << std::endl;

	l.pop_back();

	std::cout << l.size() << std::endl;

	l.push_back(3);
	l.push_back(5);
	l.push_back(737);
	//[...]
	l.push_back(0);

	std::list<int>::iterator its = l.begin();
	std::list<int>::iterator ites = l.end();

	std::cout << "before incrementation:\t" << *its << std::endl;
	++its;
	std::cout << "after incrementation:\t" << *its << std::endl;
	--its;
	std::cout << "after decrementation:\t" << *its << std::endl;
	while (its != ites)
	{
		std::cout << *its << std::endl;
		++its;
	}

	return 0;
}
