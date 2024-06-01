/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 02:05:18 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/01 17:03:27 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/MateriaSource.hpp"


MateriaSource::MateriaSource(void) {
	std::cout << BLUE "MateriaSource " RESET "default constructor is called" << std::endl;
    for (int i = 0; i < 4; ++i) {
        _memory[i] = NULL;
    }
}

MateriaSource::MateriaSource(MateriaSource const &other) {
	std::cout << BLUE "MateriaSource " RESET "copy constructor is called" << std::endl;
    for (int i = 0; i < 4; ++i) {
        if (other._memory[i])
            _memory[i] = other._memory[i]->clone();
        else
            _memory[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other) {
	std::cout << BLUE "MateriaSource " RESET "copy assignment is called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            delete _memory[i]; // Clean up current memory
            if (other._memory[i])
                _memory[i] = other._memory[i]->clone();
            else
                _memory[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource(void) {
	std::cout << BLUE "MateriaSource " RESET "destructor is called" << std::endl;
    for (int i = 0; i < 4; ++i) {
        delete _memory[i];
    }
}

void MateriaSource::learnMateria(AMateria *m) {
	std::cout << BLUE "MateriaSource " RESET "learnMateria is called" << std::endl;
    for (int i = 0; i < 4; ++i) {
        if (!_memory[i]) {
            _memory[i] = m;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const &type) {
	std::cout << BLUE "MateriaSource " RESET "createMateria is called" << std::endl;
    for (int i = 0; i < 4; ++i) {
        if (_memory[i] && _memory[i]->getType() == type) {
            return _memory[i]->clone();
        }
    }
    return NULL;
}
