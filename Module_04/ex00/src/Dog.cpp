/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 01:51:02 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/20 10:56:27 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Dog.hpp"

Dog::Dog( void ) : Animal("DOG") {
	std::cout << ORG "Dog " RESET " default constructor is called!" << std::endl;
}
Dog::Dog(Dog const & other): Animal(other){
	std::cout << ORG "Dog " RESET " copy constructor is called!" << std::endl;
	*this = other;
}
Dog & Dog::operator=(Dog const & other) {
	std::cout << ORG "Dog " RESET " copy assignment is called!" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}
Dog::~Dog( void ){
	std::cout << ORG "Dog " RESET " destructor is called!" << std::endl;
}

void Dog::makeSound( void ) const {
	std::cout << "the animal of type " GREEN << getType() << RESET " is barking!" << std::endl;
}