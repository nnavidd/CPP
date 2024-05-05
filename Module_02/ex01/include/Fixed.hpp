/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:58:52 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/05 22:16:12 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

# define BLUE	"\033[38;5;4m"
# define GREEN	"\033[38;5;2m"
# define ORG	"\033[38;5;214m"
# define RED	"\033[38;5;196m"
# define RESET	"\033[0m"


class Fixed
{
private:
	int					_raw;
	static const int	_frac_bits = 8;

public:
	Fixed( void );
	Fixed( Fixed const & othre );
	Fixed( int const raw );
	Fixed( float const raw );
	~Fixed( void );
	Fixed &	operator=(const Fixed & other);

	float	toFloat( void ) const;
	int		toInt( void ) const;
	int 	getRawBits( void ) const;
	void 	setRawBits( int const raw );
};

std::ostream & operator<<(std::ostream & out, Fixed const & other);

#endif