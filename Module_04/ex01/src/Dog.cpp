/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 01:51:02 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/24 01:12:52 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Dog.hpp"

Dog::Dog( void ) : Animal("DOG") {
	std::cout << ORG "Dog " RESET " default constructor is called!" << std::endl;
	_idea = new Brain();
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
	delete	_idea;
}

void Dog::makeSound( void ) const {
	std::cout << "the animal of type " GREEN << getType() << RESET " is barking!" << std::endl;
}
bool Dog::setData(int index, std::string idea){
	return (_idea->BsetData(index, idea));
}
void Dog::getData( int index ) const {
	std::cout << _idea->BgetData(index) << std::endl;
}