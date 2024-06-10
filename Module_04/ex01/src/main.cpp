/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 01:20:58 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/10 19:08:35 by nnabaeei         ###   ########.fr       */
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
	}
	std::cout << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}
	std::cout << std::endl;
	{
		Dog	j;	
		j.setData(20, "hi Navid");
	std::cout << std::endl;
	std::cout << RED "here is showing that is not shallow copying: " RESET << std::endl;
		{
			Dog tmp = j;
		}
	std::cout << std::endl;
		for(int i = 0; i < 100; i++)
			j.getData(i);
	}

	return (0);
}