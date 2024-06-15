/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:32:42 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/15 14:30:29 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

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

void Bureaucrat::signForm(Form & other) const {
	// if (other.getSignedAtConstruct())
	// 	std::cout << GREEN << this->getName() << RESET " Signed " MAGENTA << other.getName() << RESET << std::endl;
	// else{
	// 	std::cout << GREEN << this->getName() << RESET " Couldn't Sing " CYAN << other.getName() << RESET " because: "<< std::endl;
	// 	std::cout << CYAN << other.getName() << RESET " SingGread is:" RED << other.getSignGrade() <<
	// 	RESET " ,and is lower than " GREEN << this->getName() << RESET " SignGrade as: " RED <<
	// 	this->getRange() << RESET << std::endl;
	// }
	try{
		other.beSigned(*this);
		std::cout << MAGENTA << this->getName() << RESET " Signed " CYAN << other.getName() << RESET << std::endl;
	} catch(std::exception& e) {
		std::cout << MAGENTA << this->getName() << RESET " Couldn't Sing " CYAN << other.getName() << RESET " because:"<< std::endl;
		std::cout << CYAN << other.getName() << RESET " SingGread is:" RED << other.getSignGrade() <<
		RESET " ,and is lower than " MAGENTA << this->getName() << RESET " SignGrade as:" RED <<
		this->getRange() << RESET << std::endl;
	}
		
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & other) {
	o << GREEN << other.getName() << RESET " bureaucrat grade '" CYAN << 
	other.getRange() << RESET "'";
	return (o);
}
