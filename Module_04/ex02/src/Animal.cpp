/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 01:23:55 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/27 01:36:51 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Animal.hpp"

Animal::Animal() : _type(""){
	std::cout << BLUE "Animal " RESET "default constructor is called!" << std::endl;
}
Animal::Animal(std::string type): _type(type){
	std::cout << BLUE "Animal " RESET "name constructor is called!" << std::endl;
}
Animal::Animal(Animal const & other){
	std::cout << BLUE "Animal " RESET "copy constructor is called!" << std::endl;
	*this = other;
}
Animal & Animal::operator=(Animal const & other){
	std::cout << BLUE "Animal " RESET "copy assignment is called!" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}
Animal::~Animal(){
	std::cout << BLUE "Animal " RESET "destructor is called!" << std::endl;
}
std::string	Animal::getType( void ) const{
	std::cout << BLUE "Animal " RESET "getType func is called!" << std::endl;
	return (this->_type);
}