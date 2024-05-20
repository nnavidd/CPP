/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:24:20 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/20 14:02:03 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
    std::cout << MAGENTA "WrongCat " RESET "default constructor called" << std::endl;
    type = "WrongCat";
}
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    std::cout << MAGENTA "WrongCat " RESET "copy constructor called" << std::endl;
    *this = other;
}
WrongCat &WrongCat::operator=(const WrongCat &other) {
    std::cout << MAGENTA "WrongCat " RESET "copy assignment operator called" << std::endl;
    type = other.type;
    return (*this);
}
WrongCat::~WrongCat(void) {
    std::cout << MAGENTA "WrongCat " RESET "destructor called" << std::endl;
}
void WrongCat::makeSound(void) const {
    std::cout << "meow" << std::endl;
}
