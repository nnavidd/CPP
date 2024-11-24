/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 01:05:57 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/11/24 19:08:40 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../include/Bureaucrat.hpp"
 
 int main()
 {
	try {
		Bureaucrat	instance;
		Bureaucrat	instance1("xxx", 3);
		Bureaucrat	instance4("yyy", 150);
		Bureaucrat	instance3("zzz", 1);
		
		std::cout << BLUE "--Calling the copy constructor--" RESET <<std::endl;
		Bureaucrat	instance2(instance1);
		
		std::cout << BLUE "--Calling the copy assingment--" RESET <<std::endl;
		instance = instance2;
		
		std::cout << BLUE "Showing the << insertion overload: " RESET <<std::endl;
		std::cout << instance << std::endl;
		std::cout << instance1 << std::endl;
		std::cout << instance2 << std::endl;
		std::cout << instance3 << std::endl;
		std::cout << instance4 << std::endl;
		instance4.decrementGrade();
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	try {
		std::cout << "\n";
		Bureaucrat	instnce("eee", 2);
		std::cout << instnce << std::endl;
		instnce.decrementGrade();
		std::cout << instnce << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	try {
		std::cout << "\n";
		Bureaucrat	instnce("ddd", 1);
		std::cout << instnce << std::endl;
		instnce.incrementGrade();
		std::cout << instnce << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
 }
 