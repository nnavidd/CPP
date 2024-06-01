/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:17:00 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/01 17:25:27 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Ice.hpp"

Ice::Ice(void) : AMateria("ice") {
	std::cout << ORG "Ice " RESET "default constructor called!" << std::endl;
}

Ice::Ice(Ice const &other) : AMateria(other) {
	std::cout << ORG "Ice " RESET "copy constructor called!" << std::endl;
}

Ice &Ice::operator=(Ice const &other) {
	std::cout << ORG "Ice " RESET "copy assignment operator called!" << std::endl;
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

Ice::~Ice(void) {
	std::cout << ORG "Ice " RESET "destructor called!" << std::endl;
}

AMateria *Ice::clone(void) const {
	std::cout << ORG "Ice " RESET "clone called!" << std::endl;
	return new Ice(*this);
}

void Ice::use(ICharacter &target) {
	std::cout << GREEN "*I shoots an ice bolt at " RED << target.getName() << GREEN " *" RESET<< std::endl;
}
