/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 10:51:16 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/15 23:36:07 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

AForm::AForm( void ) : _name ("Default"), _signed_at_construct(0), _sing_grade(0), _exec_grade(0) {}

AForm::AForm(std::string name, int sgrade, int egrade) : _name(name), 
			_signed_at_construct(0), _sing_grade(sgrade), _exec_grade(egrade)
{
	if (_sing_grade < 1 || _exec_grade < 1)
		throw GradeTooHighException();
	else if (_sing_grade > 150 || _exec_grade > 150)
		throw GradeTooLowException();
}

AForm::AForm(AForm const & other) : _name(other._name), 
			_signed_at_construct(other._signed_at_construct),
			_sing_grade(other._sing_grade),
			_exec_grade(other._exec_grade) {}

AForm & AForm::operator=(AForm const & other) {
	if(this != &other)
		_signed_at_construct = other._signed_at_construct;
	return (*this);
}

AForm::~AForm( void ) {}

std::string AForm::getName() const {
	return (_name);
}

int AForm::getSignGrade() const {
	return (_sing_grade);
}

int AForm::getExecGrade() const {
	return (_exec_grade);
}

bool AForm::getSignedAtConstruct() const {
	return (_signed_at_construct);
}

void AForm::beSigned(Bureaucrat const & other) {
	if (other.getGrade() <= this->_sing_grade)
		_signed_at_construct = true;
	else
		throw GradeTooLowException();
}

bool	AForm::checkRequirements(Bureaucrat const & executor) const {
	if (!_signed_at_construct)
		throw(AForm::CheckIfSigned());
	if (executor.getGrade() > _exec_grade)
        throw AForm::GradeTooLowException();
	return (true);
}

std::ostream & operator<<(std::ostream & o, AForm const & other) {
	o <<GREEN "The form Name is: " MAGENTA << other.getName() << std::endl << GREEN "It's Signe status is:	" CYAN << 
	(other.getSignedAtConstruct() ? "Yes" : "NO") << std::endl << GREEN "It's Signe Grade is:	" CYAN <<
	other.getSignGrade() << std::endl << GREEN "Its Exec Grade is:	" CYAN << other.getExecGrade() << RESET << std::endl;

	return (o);
}