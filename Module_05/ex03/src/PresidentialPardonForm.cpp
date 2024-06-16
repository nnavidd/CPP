/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:37:23 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/15 23:45:26 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) :
	AForm("PresidentialPardonForm", 25, 5), _target("No target") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if(this != &other){
		//since the all attributes of AForm supposed to remained private, doesn't need to call AForm::operator= here
		// AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (checkRequirements(executor)) {
		std::cout << GREEN << _target << ORG " making Drilliiiiiiiiing noise!!!" RESET << std::endl;
		if ((rand() % 100) % 2)
			std::cout << GREEN << _target << ORG " has been robotomized!!!" RESET << std::endl;
		else
			std::cout << GREEN << _target << ORG " failded to robotomized!!!" RESET << std::endl;
	}
}
