/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:48:28 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/01 17:04:38 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"
#include "../include/ICharacter.hpp"

AMateria::AMateria( void ) : _type(""){
	std::cout << CYAN "AMateria" RESET " default instructor is called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type){
	std::cout << CYAN "AMateria" RESET " type instructor is called" << std::endl;
}

AMateria::AMateria(AMateria const & other): _type(other._type){
	std::cout << CYAN "AMateria" RESET " copy instructor is called" << std::endl;
}

AMateria & AMateria::operator=(AMateria const & other){
	std::cout << CYAN "AMateria" RESET " copy assingment is called" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}

AMateria::~AMateria( void ){
	std::cout << CYAN "AMateria" RESET " destructor is called" << std::endl;
}

std::string const & AMateria::getType() const {
	std::cout << CYAN "AMateria" RESET " getType is called" << std::endl;
	return (this->_type);
}

void	AMateria::use(ICharacter & target){
	std::cout << CYAN "AMateria" RESET " use is called, but did nothing" << std::endl;
	(void) target;
}