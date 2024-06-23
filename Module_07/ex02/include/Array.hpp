/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:56:00 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/23 22:34:31 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template <typename T>
class Array{
	private:
		unsigned int	_n;
		T				*_arr;
	public:
		Array( void );
		Array( T const & );
		T & operator=( T const & );
		~Array( void );

		Array(unsigned int n);
};



#endif