/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnavidd <nnavidd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:04:57 by nnavidd           #+#    #+#             */
/*   Updated: 2024/06/18 12:19:59 by nnavidd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Base.hpp"

Base* generate() {
	std::srand(static_cast<unsigned int>(std::time(NULL))); // Seed for randomness
	int randomValue = rand() % 3; // Random value between 0 and 2

	switch (randomValue) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return NULL; // This should never be reached
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	} else {
		std::cout << "Unknown type" << std::endl;
	}
}

void identify(Base& p) {
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
		std::cout << "A" << &a << std::endl;
		return;
	} catch (...) {}

	try {
		B& b = dynamic_cast<B&>(p);
		std::cout << "B" << &b << std::endl;
		return;
	} catch (...) {}

	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << "C" << &c << std::endl;
		return;
	} catch (...) {}

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
