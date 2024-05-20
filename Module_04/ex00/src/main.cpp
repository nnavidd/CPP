/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 01:20:58 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/20 14:01:17 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Animal.hpp"
# include "../include/Dog.hpp"
# include "../include/Cat.hpp"
# include "../include/WrongAnimal.hpp"
# include "../include/WrongCat.hpp"

int main (int ac, char **av){
	if(ac && av[0])
	{
		Dog	instance;
		Dog	instance1(instance);
		Dog	instance2;

		instance2 = instance1;
	}
	std::cout << std::endl;
	{
		Dog	instance;
		Cat	instance1;
		Animal	*ptr1;
		Animal	*ptr2;

		ptr1 = &instance;
		ptr2 = &instance1;
		ptr1->makeSound();
		ptr2->makeSound();
	}
	std::cout << std::endl;
	{
		Animal	*ptr = new Cat();
	
		ptr->makeSound();
		delete ptr;
	}
	std::cout << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
	}
	std::cout << std::endl;

	/*By adding the "virtual" keyword at the beginning of the destructor and 
	  the makeSound function in the WrongAnimal class, it fixes the WrongAnimal
	  class to behave like the normal Animal class. Adding "virtual" before
	  the destructor makes it possible to create a pointer of the parent instance,
	  assign it a value of the child, and delete it at the end correctly.
	  Adding "virtual" before the makeSound allows calling makeSound correctly
	  in the chils classes.
	 */
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		std::cout << "The animal type " GREEN << i->getType() <<RESET " makeSound funciton returns:" << std::endl;
		i->makeSound(); //will output the cat sound!
		std::cout << "The animal type " GREEN << meta->getType() <<RESET " makeSound funciton returns:" << std::endl;
		meta->makeSound();
		delete meta;
		delete i;
	}
	return (0);
}