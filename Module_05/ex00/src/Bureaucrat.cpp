/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:32:42 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/15 23:36:07 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("Default"), _grade(1) {}
Bureaucrat::Bureaucrat(Bureaucrat const & other) : _name(other._name), _grade(other._grade) {}
Bureaucrat::Bureaucrat(std::string name, int range) : _name(name), _grade(range) {
	if (range < 1)
		throw GradeTooHighException();
	else if (range > 150)
		throw GradeTooLowException();
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & other) {
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat( void ) {}

std::string	Bureaucrat::getName() const {
	return (_name);
}

int Bureaucrat::getGrade() const {
	return (_grade);
}

void Bureaucrat::incrementGrade(void) {
	if (_grade -1 < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	_grade--;
}

void Bureaucrat::decrementGrade(void) {
	if (_grade + 1 > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	_grade++;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & other) {
	o << GREEN << other.getName() << RESET " bureaucrat grade '" CYAN << 
	other.getGrade() << RESET "'";
	return (o);
}
