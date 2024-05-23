/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:19:06 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/20 13:35:48 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("Unspecified Animal") {
    std::cout << CYAN "WrongAnimal " RESET "default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
    std::cout << CYAN "WrongAnimal " RESET "copy constructor called" << std::endl;
    *this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    std::cout << CYAN "WrongAnimal " RESET "copy assignment operator called" << std::endl;
    type = other.type;
    return (*this);
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << CYAN "WrongAnimal " RESET "destructor called" << std::endl;
}

std::string WrongAnimal::getType(void) const {
    return (type);
}

void WrongAnimal::makeSound(void) const {
    std::cout << "HI" << std::endl;
}
