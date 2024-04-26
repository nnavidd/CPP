/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 00:25:45 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/04/26 18:25:37 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"


Zombie::Zombie(): _Name(""){}
Zombie::~Zombie(){std::cout  << this->_Name << " Is Destroyed!" << std::endl;}
void    Zombie::Announce(void){std::cout << this->_Name << ": BraiiiiiiinnnzzzZ..." << std::endl;}
void    Zombie::setName( std::string name) {this->_Name = name;}