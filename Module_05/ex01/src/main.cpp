/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 01:05:57 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/15 16:00:59 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../include/Bureaucrat.hpp"
 #include "../include/Form.hpp"
 
 int main()
 {
	// The sign grade is lower than 1
	try {
		Form	instance("yyy", 0, 3);

	} catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	// The exec grade is heigher than 150
	try {
		Form	instance("yyy", 5, 151);

	} catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try {
		
		// Name, signe grade, exec grade
		Form	instance1("yyy", 5, 3);
		Form	instance2("zzz", 3, 3);
		Form	instance3;
		Bureaucrat	test("Bureaucrat", 4);

		std::cout << instance1 << std::endl;
		instance1.beSigned(test);
		std::cout << instance1 << std::endl;
		std::cout << instance2 << std::endl;
		std::cout << instance3 << std::endl;

		//could'nt sign
		std::cout << std::endl;
		std::cout << RED "couldn't sing expample:" RESET << std::endl;
		test.signForm(instance2);
		

		//signed
		std::cout << std::endl;
		std::cout << RED "singed expample:" RESET << std::endl;
		test.signForm(instance1);
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
 }
 