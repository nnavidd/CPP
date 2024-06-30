/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnavidd <nnavidd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:22:31 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/07/01 00:27:52 by nnavidd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MutantStack.hpp"

int main() {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	mstack.showContainerElements();
	
	std::cout << MAGENTA "Showing the top element of stack: " CYAN;
	std::cout << mstack.top() << RESET << std::endl;
	
	// deleting the last element of the stack with the pop command
	std::cout << ORG "Calling the pop to delete the top element (last element)" RESET << std::endl;
	mstack.pop();
	mstack.showContainerElements();
	
	/* sinc the MutantStack is inheritated of the std::stack, therefor
	   the size function of that container is applicable for this container as well */
	std::cout << MAGENTA "The size of Containter: " CYAN << mstack.size() << RESET << std::endl;
	
	/*Adding the element to the MutantStack container with the push command*/
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	mstack.showContainerElements();

	/*Defining iterator type of MutantStack container and iterat through an instance of that*/
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	// Just to show that this operators are applicable
	++it;
	--it;
	
	std::cout << ORG "Creating an iterator to expose the elements of MutantStack container: " RESET << std::endl;
	// Go through the container to expose its elements
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	
	// make an instance of std::stack with an instance of MutantStack
	std::stack<int> s(mstack);
	std::cout << GREEN "The top of a std::stack instance is: " CYAN << s.top() << RESET << std::endl;
	s.push(11);
	std::cout << GREEN "The top of a std::stack instance after call push is: " CYAN << s.top() << RESET << std::endl;
	
	return 0;
}
