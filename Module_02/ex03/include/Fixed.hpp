/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:58:52 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/09 01:38:25 by nnabaeei         ###   ########.fr       */
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
    Fixed & operator=( Fixed const & other );

    bool    operator>( Fixed const & other ) const ;
    bool    operator<( Fixed const & other ) const ;
    bool    operator>=( Fixed const & other ) const ;
    bool    operator<=( Fixed const & other ) const ;
    bool    operator==( Fixed const & other ) const ;
    bool    operator!=( Fixed const & other ) const ;

    Fixed   operator+( Fixed const & other ) const ;
    Fixed   operator-( Fixed const & other ) const ;
    Fixed   operator*( Fixed const & other ) const ;
    Fixed   operator/( Fixed const & other ) const ;

    Fixed & operator++( void ); // prefix
    Fixed   operator++( int ); 	// postfix
    Fixed & operator--( void ); // prefix
    Fixed   operator--( int ); 	// postfix

	static Fixed & min( Fixed & a, Fixed & b );
    static Fixed & max( Fixed & a, Fixed & b );
    static const Fixed& min( const Fixed & a, const Fixed & b );
    static const Fixed& max( const Fixed & a, const Fixed & b );

	float	toFloat( void ) const;
	int		toInt( void ) const;
	int 	getRawBits( void ) const;
	void 	setRawBits( int const raw );
};

std::ostream & operator<<(std::ostream & out, Fixed const & other);

#endif