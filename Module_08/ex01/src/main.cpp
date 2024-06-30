/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnavidd <nnavidd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 01:51:28 by nnavidd           #+#    #+#             */
/*   Updated: 2024/06/30 12:23:18 by nnavidd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

int main() {
	try {
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		sp.showContainerElements();
		std::cout << sp.shortestSpan() << std::endl; // Output: 2
		std::cout << sp.longestSpan() << std::endl;  // Output: 14

		// Test adding multiple numbers
		Span largeSpan(10000);
		std::vector<int> numbers;
		srand(time(NULL));
		for (int i = 0; i < 10000; ++i) {
			numbers.push_back(rand() % 1000);
		}
		largeSpan.addNumbers(numbers.begin(), numbers.end());
		largeSpan.showContainerElements(2, 5);
		std::cout << largeSpan.shortestSpan() << std::endl; // Output: 1
		std::cout << largeSpan.longestSpan() << std::endl;  // Output: 9999
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
