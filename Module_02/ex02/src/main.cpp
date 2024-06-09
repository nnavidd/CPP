/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:51:31 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/09 20:45:00 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << std::endl;
	Fixed c(42.42f);
	Fixed d(b);
	Fixed e(5.5f);
	
	std::cout << GREEN "Testing constructors and assignment operator:" RESET << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "e: " << e << std::endl;

	std::cout << std::endl;
	a = Fixed(1234.4321f);
	std::cout << "a (after assignment): " << a << std::endl;

	std::cout << std::endl;
	// Test arithmetic operators
	std::cout << GREEN "Testing arithmetic operators:" RESET << std::endl;
	Fixed sum = b + c;
	Fixed difference = b - c;
	Fixed product = b * c;
	Fixed quotient = b / c;

	std::cout << "b + c: " << sum << std::endl;
	std::cout << "b - c: " << difference << std::endl;
	std::cout << "b * c: " << product << std::endl;
	std::cout << "b / c: " << quotient << std::endl;

	std::cout << std::endl;
	// Test comparison operators
	std::cout << GREEN "Testing comparison operators:" RESET << std::endl;
	std::cout << "b > c: " << (b > c) << std::endl;
	std::cout << "b < c: " << (b < c) << std::endl;
	std::cout << "b >= c: " << (b >= c) << std::endl;
	std::cout << "b <= c: " << (b <= c) << std::endl;
	std::cout << "b == c: " << (b == c) << std::endl;
	std::cout << "b != c: " << (b != c) << std::endl;

	std::cout << std::endl;
	// Test increment and decrement operators
	std::cout << GREEN "Testing increment and decrement operators:" RESET << std::endl;
	Fixed preIncrement = ++e;
	Fixed postIncrement = e++;
	Fixed preDecrement = --e;
	Fixed postDecrement = e--;

	std::cout << "++e: " << preIncrement << std::endl;
	std::cout << "e++: " << postIncrement << std::endl;
	std::cout << "--e: " << preDecrement << std::endl;
	std::cout << "e--: " << postDecrement << std::endl;
	std::cout << "e  : " << e << std::endl;

	std::cout << std::endl;
	// Test min and max functions
	std::cout << GREEN "Testing min and max functions:" RESET << std::endl;
	Fixed f(7.7f);
	Fixed g(3.3f);
	Fixed h(3.3f);

	std::cout << "min(f, g): " << Fixed::min(f, g) << std::endl;
	std::cout << "min(g, h): " << Fixed::min(g, h) << std::endl;
	std::cout << "max(f, g): " << Fixed::max(f, g) << std::endl;
	std::cout << "max(g, h): " << Fixed::max(g, h) << std::endl;

	std::cout << std::endl;
	// Test conversion to int
	std::cout << GREEN "Testing conversion to int:" RESET << std::endl;
	std::cout << "a as int: " << a.toInt() << std::endl;
	std::cout << "b as int: " << b.toInt() << std::endl;
	std::cout << "c as int: " << c.toInt() << std::endl;

	std::cout << std::endl;
	// Test raw bit manipulation
	std::cout << GREEN "Testing raw bit manipulation:" RESET << std::endl;
	int rawBits = e.getRawBits();
	std::cout << "e's raw bits: " << rawBits << std::endl;
	e.setRawBits(rawBits);
	std::cout << "e after setting raw bits: " << e << std::endl;

return 0;
}