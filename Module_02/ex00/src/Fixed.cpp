/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:27:39 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/08 14:30:37 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed(): _raw(0) {
	std::cout << GREEN "Default constructor called " RESET << std::endl;
}
Fixed::Fixed(Fixed const & other) {
	std::cout << RED "Copy constructor called" RESET << std::endl;
	*this = other;
}
Fixed & Fixed::operator=(Fixed const & other)
{
	std::cout << BLUE "Copy assignment operator called" RESET << std::endl;
	if (this != &other)
		this->_raw = other.getRawBits();
	return (*this);
}
Fixed::~Fixed() {
	std::cout << GREEN "Destructor called" RESET << std::endl;
}

int	Fixed::getRawBits( void ) const{
	std::cout << ORG "getRawBits member function called" RESET << std::endl;
	return (this->_raw);
}

void Fixed::setRawBits( int const raw ){
	std::cout << GREEN "setRawBits member function called" RESET << std::endl;
	this->_raw = raw;
}

std::ostream & operator<<(std::ostream & out, Fixed const & other)
{
	out << "The Value Of The Integer Is: " << other.getRawBits();
	return (out);
}
