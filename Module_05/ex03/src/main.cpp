/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 01:05:57 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/16 09:40:04 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"

int main() {
	{
		std::cout << std::endl << RED "--------execute the" GREEN " ShrubberyCreationForm" RED " type of form---------" RESET << std::endl;
		Intern		b;
		AForm		*form = NULL;
		Bureaucrat	bur("Ampt", 2);

		form = b.makeForm("ShrubberyCreationForm", "xxx");
		bur.executeForm(*form);
		bur.signForm(*form);
		bur.executeForm(*form);
		if (form != NULL)
			delete form;
	}

	{
		std::cout << std::endl << RED "--------execute the" GREEN " RobotmyRequestForm" RED " type of form---------" RESET << std::endl;
		Intern	b;
		AForm	*form = b.makeForm("RobotomyRequestForm", "yyy");
		Bureaucrat	bur("42_institute", 1);

		bur.executeForm(*form);
		bur.signForm(*form);
		bur.executeForm(*form);
		if (form)
			delete form;
	}

	{
		std::cout << std::endl << RED "--------execute the" GREEN " PresidentialPardonForm" RED " type of form---------" RESET << std::endl;
		Intern	b;
		AForm	*form = b.makeForm("PresidentialPardonForm", "zzz");
		Bureaucrat	bur("Burger", 1);

		bur.executeForm(*form);
		bur.signForm(*form);
		bur.executeForm(*form);
		if (form)
			delete form;
	}

	{
		std::cout << std::endl << RED "--------execute the" GREEN " WRONG_FORM" RED " type of form---------" RESET << std::endl;
		Intern	b;
		AForm	*form =  b.makeForm("WRONG_FORM", "zzz");;
		Bureaucrat	bur("Burger", 1);

		if (form) {
			bur.executeForm(*form);
			bur.signForm(*form);
			bur.executeForm(*form);
			printf("hiiiiiiiii\n");
				delete form;
		}
	}

    return 0;
}
