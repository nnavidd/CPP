/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 01:51:28 by nnavidd           #+#    #+#             */
/*   Updated: 2024/06/30 14:40:02 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

template <typename T>
void	showSpans(T const & p){
	std::cout << GREEN "Shortest Span: " MAGENTA << p.shortestSpan() << RESET << std::endl; 
	std::cout << GREEN "Longest  Span: " MAGENTA << p.longestSpan() << RESET << std::endl;  
}

int main() {
	try {
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		sp.showContainerElements(5);
		showSpans(sp);

		// Test adding multiple numbers
		Span largeSpan(10000);
		std::vector<int> numbers;
		srand(time(NULL)); //rand func check srand according time to generate new random
		for (int i = 0; i < 10000; ++i) {
			numbers.push_back(rand() % 10000);
		}
		largeSpan.addNumbers(numbers.begin(), numbers.end());
		largeSpan.showContainerElements(10);
		showSpans(largeSpan);
	}
	catch (const std::exception &e) {
		std::cerr << RED"Error: " RESET << e.what() << std::endl;
	}

	return 0;
}
