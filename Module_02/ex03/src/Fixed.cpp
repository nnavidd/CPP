/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:27:39 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/10 12:51:29 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed(): _raw(0){
	// std::cout << GREEN "Default constructor called" RESET << std::endl;
}

Fixed::Fixed(int const raw){
	// std::cout << "Int constructor called" << std::endl;
	this->_raw = raw << _frac_bits;
}

Fixed::Fixed(float const raw){
	// std::cout << "Float constructor called" << std::endl;
	this->_raw = roundf(raw * (1 << _frac_bits));
}

Fixed::Fixed(Fixed const & other) {
	// std::cout << RED "Copy constructor called" RESET << std::endl;
	*this = other;
}

Fixed::~Fixed(){
	// std::cout << GREEN "Destructor called" RESET << std::endl;
}

Fixed & Fixed::operator=(Fixed const & other)
{
	// std::cout << BLUE "Copy assignment operator called" RESET << std::endl;
	if (this != &other)
		this->_raw = other.getRawBits();
	return (*this);
}


bool Fixed::operator>(Fixed const & other ) const {
	return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<(Fixed const & other ) const {
	return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator>=(Fixed const & other ) const {
	return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=(Fixed const & other ) const {
	return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator==(Fixed const & other ) const {
	return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(Fixed const & other ) const {
	return (this->getRawBits() != other.getRawBits());
}



Fixed   Fixed::operator+( Fixed const & other ) const {
	return (this->toFloat() + other.toFloat());
}

Fixed   Fixed::operator-( Fixed const & other ) const {
	return (this->toFloat() - other.toFloat());
}

Fixed   Fixed::operator*( Fixed const & other ) const {
	return (this->toFloat() * other.toFloat());
}

Fixed   Fixed::operator/( Fixed const & other ) const {
	return (this->toFloat() / other.toFloat());
}


Fixed & Fixed::operator++( void ) {
	this->_raw++;
	return (*this);
}

Fixed	Fixed::operator++( int ) {
	Fixed	tmp(*this);

	this->_raw++;
	return (tmp);
}

Fixed & Fixed::operator--( void ) {
	this->_raw--;
	return (*this);
}

Fixed   Fixed::operator--( int ) {
	Fixed	tmp(*this);

	this->_raw--;
	return (tmp);
}


Fixed & Fixed::min(Fixed & a, Fixed & b){
	return((a < b) ? a : b);	
}

const Fixed & Fixed::min(const Fixed & a, const Fixed & b){
	return((a < b) ? a : b);	
}

Fixed & Fixed::max(Fixed & a, Fixed & b){
	return((a > b) ? a : b);	
}

const Fixed & Fixed::max(const Fixed & a, const Fixed & b){
	return((a > b) ? a : b);	
}


float Fixed::toFloat( void ) const
{
	return ((float)_raw / (1 << _frac_bits));
}

int	Fixed::toInt( void ) const
{
	return (this->_raw >> _frac_bits);
} 

int	Fixed::getRawBits( void ) const{
	// std::cout << ORG "getRawBits member function called" RESET << std::endl;
	return (this->_raw);
}

void Fixed::setRawBits( int const raw ){
	this->_raw = raw;
}

std::ostream & operator<<(std::ostream & out, Fixed const & other)
{
	out << other.toFloat();
	return (out);
}
