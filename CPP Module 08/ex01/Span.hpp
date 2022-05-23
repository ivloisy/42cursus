/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 03:17:30 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/11 15:44:49 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <climits>
# include <vector>


class	Span
{

	private:

		unsigned int		_N;
		std::vector<int>	_span;

	public:

		Span();
		Span( Span const & src );
		Span( unsigned int N );
		~Span();

		Span				& operator=( Span const & rhs );

		void				addNumber(int n);
		void				addRange(std::vector<int>::iterator b, std::vector<int>::iterator e);
		int					shortestSpan() const;
		int					longestSpan() const;

		unsigned int		getN() const;
		std::vector<int>	getSpan() const;

		class	SpanFullException : public std::exception
		{
			public:
				virtual const char	* what() const throw()
				{
					return "The Span is full.";
				}
		};

		class	NotEnoughException : public std::exception
		{
			public:
				virtual const char	* what() const throw()
				{
					return "There are not enough elements to compare.";
				}
		};

		class	tooBigRangeException : public std::exception
		{
			public:
				virtual const char	* what() const throw()
				{
					return "The range is too big.";
				}
		};

};

std::ostream &			operator<<( std::ostream & o, Span const & i );

#endif /* ************************************************************ SPAN_H */