/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:58:50 by ivloisy           #+#    #+#             */
/*   Updated: 2022/02/10 13:59:41 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class Array
{

	private:
		unsigned int	_size;
		T				*_array;

	public:

		Array<T>() :  _size(0), _array(NULL)
		{
			return ;
		}

		Array<T>( Array<T> const & src ) :  _size(0), _array(NULL)
		{
			*this = src;
			return ;
		}

		Array<T>( unsigned int n ) : _size(n), _array(new T[n])
		{
			return ;
		}

		~Array<T>() 
		{
			delete [] this->_array;
			return ;
		}

		Array<T> &		operator=( Array<T> const & rhs )
		{
			if ( this != &rhs )
			{
				this->_size = rhs._size;
				if (this->_array != NULL)
					delete [] _array;
				if (this->_size == 0)
					this->_array = NULL;
				else
					this->_array = new T[this->_size];
				for (unsigned int i = 0; i < this->_size; i++)
					_array[i] = rhs._array[i];
			}
			return *this;
		}

		T &		operator[]( unsigned int idx )
		{
			if ( idx < 0 || idx >= this->_size || this->_array == NULL)
				throw std::exception();
			return _array[idx];
		}

		unsigned int size() const
		{
			return _size;
		}

};

#endif /* *********************************************************** ARRAY_H */
