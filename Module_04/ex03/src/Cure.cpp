/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:13:35 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/01 09:53:29 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
	std::cout << GREEN "Cure " RESET "default constructor called!" << std::endl;
}

Cure::Cure(Cure const &other) : AMateria(other) {
	std::cout << GREEN "Cure " RESET "copy constructor called!" << std::endl;
}

Cure &Cure::operator=(Cure const &other) {
	std::cout << GREEN "Cure " RESET "copy assignment operator called!" << std::endl;
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

Cure::~Cure(void) {
	std::cout << GREEN "Cure " RESET "destructor called!" << std::endl;
}

AMateria *Cure::clone(void) const {
	std::cout << GREEN "Cure " RESET "clone called!" << std::endl;
	return new Cure(*this);
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
