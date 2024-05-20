/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 01:51:02 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/20 10:55:46 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Cat.hpp"

Cat::Cat( void ) : Animal("CAT") {
	std::cout << MAGENTA "Cat " RESET " default constructor is called!" << std::endl;
}
Cat::Cat(Cat const & other): Animal(other){
	std::cout << MAGENTA "Cat " RESET " copy constructor is called!" << std::endl;
	*this = other;
}
Cat & Cat::operator=(Cat const & other) {
	std::cout << MAGENTA "Cat " RESET " copy assignment is called!" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}
Cat::~Cat( void ){
	std::cout << MAGENTA "Cat " RESET " destructor is called!" << std::endl;
}

void Cat::makeSound( void ) const {
	std::cout << "the animal of type " GREEN << getType() << RESET " is miaowing!" << std::endl;
}