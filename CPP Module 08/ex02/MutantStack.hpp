/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 01:58:58 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/11 19:24:04 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{

	public:

		MutantStack<T>()/*  : std::stack<T>() */
		{
			std::cout << "\033[2;37m" << "MutantStack constructor called" << "\033[0m" << std::endl;
			return ;
		}

		MutantStack<T>( MutantStack<T> const & src )/*  : std::stack<T>(src) */
		{
			*this = src;
			std::cout << "\033[2;37m" << "MutantStack copy constructor called" << "\033[0m" << std::endl;
			return ;
		}

		virtual ~MutantStack<T>()
		{
			std::cout << "\033[2;37m" << "MutantStack destructor called" << "\033[0m" << std::endl;
			return ;
		}

		MutantStack<T> &		operator=( MutantStack<T> const & rhs )
		{
			if (*this != rhs)
				//static_cast< std::stack<T> >(*this) = static_cast< std::stack<T> >(rhs);
				this->c = rhs.c;
			return *this;
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		
		iterator	begin()
		{
			return this->c.begin();
		}

		iterator	end()
		{
			return this->c.end();
		}

	private:

};

#endif /* ***************************************************** MUTANTSTACK_H */