/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:32:42 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/15 00:43:38 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("Default"), _range(1) {}
Bureaucrat::Bureaucrat(Bureaucrat const & other) : _name(other._name), _range(other._range) {}
Bureaucrat::Bureaucrat(std::string name, int range) : _name(name), _range(range) {
	if (range < 1)
		throw GradeTooHighException();
	else if (range > 150)
		throw GradeTooLowException();
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & other) {
	if (this != &other)
		this->_range = other._range;
	return (*this);
}

Bureaucrat::~Bureaucrat( void ) {}

std::string	Bureaucrat::getName() const {
	return (_name);
}

int Bureaucrat::getRange() const {
	return (_range);
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & other) {
	o << GREEN << other.getName() << RESET " bureaucrat grade '" CYAN << 
	other.getRange() << RESET "'";
	return (o);
}
