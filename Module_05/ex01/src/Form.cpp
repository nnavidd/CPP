/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 10:51:16 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/15 14:25:13 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

Form::Form( void ) : _name ("Default"), _signed_at_construct(0), _sing_grade(0), _exec_grade(0) {}

Form::Form(std::string name, int sgrade, int egrade) : _name(name), 
			_signed_at_construct(0), _sing_grade(sgrade), _exec_grade(egrade)
{
	if (_sing_grade < 1 || _exec_grade < 1)
		throw GradeTooHighException();
	else if (_sing_grade > 150 || _exec_grade > 150)
		throw GradeTooLowException();
}

Form::Form(Form const & other) : _name(other._name), 
			_signed_at_construct(other._signed_at_construct),
			_sing_grade(other._sing_grade),
			_exec_grade(other._exec_grade) {}

Form & Form::operator=(Form const & other) {
	if(this != &other)
		_signed_at_construct = other._signed_at_construct;
	return (*this);
}

Form::~Form( void ) {}

std::string Form::getName() const {
	return (_name);
}

int Form::getSignGrade() const {
	return (_sing_grade);
}

int Form::getExecGrade() const {
	return (_exec_grade);
}

bool Form::getSignedAtConstruct() const {
	return (_signed_at_construct);
}

void Form::beSigned(Bureaucrat const & other) {
	if (other.getRange() <= this->_sing_grade)
		_signed_at_construct = true;
	else
		throw GradeTooLowException();
}

std::ostream & operator<<(std::ostream & o, Form const & other) {
	o <<GREEN "The form Name is: " MAGENTA << other.getName() << std::endl << GREEN "It's Signe status is:	" CYAN << 
	(other.getSignedAtConstruct() ? "Yes" : "NO") << std::endl << GREEN "It's Signe Grade is:	" CYAN <<
	other.getSignGrade() << std::endl << GREEN "Its Exec Grade is:	" CYAN << other.getExecGrade() << RESET << std::endl;

	return (o);
}