/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 01:05:57 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/15 14:32:28 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../include/Bureaucrat.hpp"
 #include "../include/Form.hpp"
 
 int main()
 {
	try {
		/* To show the Bure exception, assing a value less than 1
		 or higher than 150 to second blow arg */
		// Form	instance1("yyy", 5, 3);
		
		// Name, signe grade, exec grade
		Form	instance1("yyy", 5, 3);
		Form	instance2("zzz", 3, 3);
		Form	instance3;
		Bureaucrat	test("Bureaucrat", 4);
		/* To show the Bure exception, assing a value less than 1
		 or higher than 150 to second blow arg */
		// Bureaucrat	test("Bru", 0);

		std::cout << instance1 << std::endl;
		instance1.beSigned(test);
		std::cout << instance1 << std::endl;
		std::cout << instance2 << std::endl;
		std::cout << instance3 << std::endl;

		std::cout << std::endl;
		std::cout << RED "couldn't sing expample:" RESET << std::endl;
		test.signForm(instance2);
		
		std::cout << std::endl;
		std::cout << RED "singed expample:" RESET << std::endl;
		test.signForm(instance1);
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
 }
 