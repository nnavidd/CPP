/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 01:05:57 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/16 12:24:03 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main() {
	{
		Bureaucrat bru("xxx", 140);
		ShrubberyCreationForm s("Tree");
		RobotomyRequestForm r("robot");
		PresidentialPardonForm p("Boss");
		
		bru.executeForm(s);
		bru.signForm(s);
		bru.executeForm(s);
		std::cout << std::endl;
		bru.executeForm(r);
		bru.signForm(r);
		bru.executeForm(r);
		std::cout << std::endl;
		bru.executeForm(p);
		bru.signForm(p);
		bru.executeForm(p);
	}
	std::cout << std::endl;
	{
		Bureaucrat bru("42_institute", 1);
		RobotomyRequestForm r("ROBBOTT");
		PresidentialPardonForm p("TRUMP");
		ShrubberyCreationForm s("Flower");

		bru.executeForm(s);
		bru.signForm(s);
		bru.executeForm(s);
		std::cout << std::endl;
		bru.executeForm(r);
		bru.signForm(r);
		bru.executeForm(r);
		std::cout << std::endl;
		bru.executeForm(p);
		bru.signForm(p);
		bru.executeForm(p);
	}

	return 0;
}
