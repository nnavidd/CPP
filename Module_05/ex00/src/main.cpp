/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 01:05:57 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/15 00:44:55 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../include/Bureaucrat.hpp"
 
 int main()
 {
	try {
		Bureaucrat	instance;
		Bureaucrat	instance1("xxx", 3);
		Bureaucrat	instance2(instance1);
		Bureaucrat	instance4("yyy", 150);
		Bureaucrat	instance3("zzz", 1);

		instance = instance2;
		std::cout << instance << std::endl;
		std::cout << instance1 << std::endl;
		std::cout << instance2 << std::endl;
		std::cout << instance3 << std::endl;
		std::cout << instance4 << std::endl;
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
 }
 