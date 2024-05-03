/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:27:39 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/04 00:50:12 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed(): _fp(0){
	std::cout << GREEN "Default constructor called " RESET << std::endl;
}
Fixed::Fixed(Fixed const & other) {
	std::cout << RED "Copy constructor called" RESET << std::endl;
	*this = other;
}
Fixed::~Fixed(){
	std::cout << GREEN "Destructor called" RESET << std::endl;
}
Fixed & Fixed::operator=(Fixed const & other)
{
	std::cout << BLUE "Copy assignment operator called" RESET << std::endl;
	if (this != &other)
		this->_fp = other.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const{
	std::cout << ORG "getRawBits member function called" RESET << std::endl;
	return (this->_fp);
}

void Fixed::setRawBits( int const raw ){
	this->_fp = raw;
}

std::ostream & operator<<(std::ostream & out, Fixed const & other)
{
	out << "The Value Of The Integer Is: " << other.getRawBits();
	return (out);
}
