/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:55:37 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/15 23:40:43 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) :
	AForm("RobotomyRequestForm", 72, 45), _target("No target") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if(this != &other){
		//since the all attributes of AForm supposed to remained private, doesn't need to call AForm::operator= here
		// AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (checkRequirements(executor)){
		std::cout << GREEN << _target << ORG " has been pardoned by Zaphod Beeblebrox" RESET << std::endl;
	}
}
