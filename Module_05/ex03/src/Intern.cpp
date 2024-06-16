/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 00:10:54 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/16 09:43:30 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
# include <cstdio>

Intern::Intern( void ){}

Intern::Intern(Intern const & other){
	*this = other;
}

Intern & Intern::operator=(Intern const & other){
	if (this != &other)
		*this = other;
	return (*this);
}

Intern::~Intern( void ){}

AForm * Intern::makeForm(std::string FormName, std::string target){
	std::string	FormType[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	int			i = 0;
	AForm		*ptr = NULL;

	for (i = 0; i < 3 && FormType[i] != FormName; i++);
	try{
		switch (i)
		{
		case 0:
			// return (new PresidentialPardonForm(target));
			ptr = new PresidentialPardonForm(target);
			break;
		case 1:
			
			ptr = new RobotomyRequestForm(target);
			break;
		case 2:
			
			ptr = new ShrubberyCreationForm(target);
			break;
		case 3:
			throw (Intern::Exception());
			break;
		}
	} catch(std::exception& e) {
		std::cout << RED << FormName + ": " RESET;
		std::cout << e.what() << std::endl;
	}
	return (ptr);
}