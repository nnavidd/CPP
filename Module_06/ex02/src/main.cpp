/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:04:57 by nnavidd           #+#    #+#             */
/*   Updated: 2024/06/18 08:24:16 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Base.hpp"

Base* generate() {
	std::srand(static_cast<unsigned int>(std::time(NULL))); // Seed for randomness
	int randomValue = rand() % 3; // Random value between 0 and 2

	switch (randomValue) {
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (NULL);
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << ORG "The class'" GREEN "A" ORG "'is randomly generated!" RESET << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << ORG "The class'" GREEN "B" ORG "'is randomly generated!" RESET  << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << ORG "The class'" GREEN "C" ORG "'is randomly generated!" RESET  << std::endl;
	else
		std::cout << RED "Unknown type" RESET << std::endl;
}

void identify(Base& p) {

	/* *******NOTICE: the (std::bad_cast&) doesn't compile with c++98 flag in linux,
	therefore in case of need to be run on linux it should turns to catch (...) */
	// try {
	//     (void)dynamic_cast<A&>(p);
	//     std::cout << "A" << std::endl;
	// } catch (std::bad_cast&) {}

	// try {
	//     (void)dynamic_cast<B&>(p);
	//     std::cout << "B" << std::endl;
	// } catch (std::bad_cast&) {}

	// try {
	//     (void)dynamic_cast<C&>(p);
	//     std::cout << "C" << std::endl;
	// } catch (std::bad_cast&) {}
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << ORG "Class'" GREEN "A" ORG"'address is:" CYAN << &a << RESET << std::endl;
		return ;
	} catch (std::bad_cast& bc) {}

	try {
		B& b = dynamic_cast<B&>(p);
		std::cout << ORG "Class'" GREEN "B" ORG"'address is:" CYAN << &b << RESET << std::endl;
		return ;
	} catch (...) {}

	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << ORG "Class'" GREEN "C" ORG"'address is:" CYAN << &c << RESET << std::endl;
		return ;
	} catch (std::bad_cast& bc) {}

	std::cout << "Unknown type" << std::endl;
}

int main() {
	// Generate a random instance of A, B, or C
	Base* basePtr = generate();

	// Identify the type using pointer
	identify(basePtr);

	// Identify the type using reference
	identify(*basePtr);

	// Clean up
	delete basePtr;

	return 0;
}
