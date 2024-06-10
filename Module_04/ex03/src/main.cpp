/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 01:05:57 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/10 19:45:20 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../include/MateriaSource.hpp"
 #include "../include/Character.hpp"
 #include "../include/Ice.hpp"
 #include "../include/Cure.hpp"
 
 int main()
 {
	IMateriaSource* src = new MateriaSource();
std::cout << std::endl;
	src->learnMateria(new Ice());
std::cout << std::endl;
	src->learnMateria(new Cure());
std::cout << std::endl;
	ICharacter* me = new Character("me");
std::cout << std::endl;
	AMateria* tmp;
std::cout << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
std::cout << std::endl;
	ICharacter* bob = new Character("bob");
std::cout << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
std::cout << std::endl;
	delete bob;
	delete me;
	delete src;
	return 0;
 }
 