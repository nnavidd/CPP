/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 01:51:02 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/26 23:54:24 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Dog.hpp"

Dog::Dog( void ) : Animal("DOG"), _brain(new Brain()) {
	std::cout << ORG "Dog " RESET " default constructor is called!" << std::endl;
	// _brain = new Brain();
}
Dog::Dog(Dog const & other): Animal(other), _brain(new Brain(*other._brain)){
	std::cout << ORG "Dog " RESET " copy constructor is called!" << std::endl;
	// *this = other; 
	/*Using *this = other inside the copy constructor is not a good practice
	 as it can lead to inefficiencies and incorrect behavior.*/
}
Dog & Dog::operator=(Dog const & other) {
	std::cout << ORG "Dog " RESET " copy assignment is called!" << std::endl;
	if (this != &other){
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}
Dog::~Dog( void ){
	std::cout << ORG "Dog " RESET " destructor is called!" << std::endl;
	delete	_brain;
}

void Dog::makeSound( void ) const {
	std::cout << "the animal of type " GREEN << getType() << RESET " is barking!" << std::endl;
}
bool Dog::setData(int index, std::string idea){
	return (_brain->BsetData(index, idea));
}
void Dog::getData( int index ) const {
	std::cout << _brain->BgetData(index) << std::endl;
}