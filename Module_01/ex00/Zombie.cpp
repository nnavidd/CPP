/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:30:11 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/04/27 09:30:13 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"


Zombie::Zombie(std::string name): _Name(name){std::cout << this->_Name << " Is Created!" << std::endl;}
Zombie::~Zombie(){std::cout  << this->_Name << " Is Destroyed!" << std::endl;}
void    Zombie::Announce(void){std::cout << this->_Name << ": BraiiiiiiinnnzzzZ..." << std::endl;}
