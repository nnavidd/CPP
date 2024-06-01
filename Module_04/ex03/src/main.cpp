/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 01:05:57 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/01 10:22:19 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../include/MateriaSource.hpp"
 #include "../include/Character.hpp"
 #include "../include/Ice.hpp"
 #include "../include/Cure.hpp"
 
 int main()
 {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
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
 