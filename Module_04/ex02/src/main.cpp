/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 01:20:58 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/10 19:25:34 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Animal.hpp"
# include "../include/Dog.hpp"
# include "../include/Cat.hpp"
# include "../include/WrongAnimal.hpp"
# include "../include/WrongCat.hpp"
# include "../include/Brain.hpp"

int main (int ac, char **av){
	if(ac && av[0])
	{
		Dog	instance;
		Dog	instance1(instance);
		Dog	instance2;

		instance2 = instance1;
		
		// Animal test; 
		/*Now Animal is abstract class, and its not possible to make an instance of it, but
		making pointer is possible as below*/
	}
	std::cout << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		j->makeSound();
		i->makeSound();
		delete j;//should not create a leak
		delete i;
	}
	return (0);
}