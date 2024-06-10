/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 01:51:02 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/10 19:14:49 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Cat.hpp"

Cat::Cat( void ) : Animal("CAT"), _brain(new Brain()){
	std::cout << MAGENTA "Cat " RESET " default constructor is called!" << std::endl;
	// _brain = new Brain();
}
Cat::Cat(Cat const & other): Animal(other), _brain(new Brain(*other._brain)){
	std::cout << MAGENTA "Cat " RESET " copy constructor is called!" << std::endl;
	// *this = other;
}
Cat & Cat::operator=(Cat const & other) {
	std::cout << MAGENTA "Cat " RESET " copy assignment is called!" << std::endl;
	if (this != &other){
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);	
	}
	return (*this);
}
Cat::~Cat( void ){
	std::cout << MAGENTA "Cat " RESET " destructor is called!" << std::endl;
	delete	_brain;
}

void Cat::makeSound( void ) const {
	std::cout << "the animal of type " GREEN << getType() << RESET " is miaowing!" << std::endl;
}
bool Cat::setData(int index, std::string const idea){
	return (_brain->BsetData(index, idea));
}
void Cat::getData( int index ) const {
	std::cout << ORG << _type << RESET " type is calling: " <<  _brain->BgetData(index) << std::endl;
}