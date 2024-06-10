/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:31:17 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/10 19:24:25 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Brain.hpp"

Brain::Brain( void ){
	std::cout << MAGENTA "Brain " RESET " defaul constructor is called!" << std::endl;
	for(int i = 0; i < 100; i++)
		_ideas[i] = "";
}
Brain::Brain(Brain const & other){
	std::cout << MAGENTA "Brain " RESET "copy constructor is called!" << std::endl;
	for(int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
}
Brain & Brain::operator=(Brain const & other){
	std::cout << MAGENTA "Brain " RESET "copy assignment is called!" << std::endl;
	if (this != &other){
		for(int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return (*this);
}
Brain::~Brain( void ){
	std::cout << MAGENTA "Brain " RESET "destructor is called!" << std::endl;
}
bool Brain::BsetData(int index, std::string idea){
	std::cout << MAGENTA "Brain " RESET "setData is called!" << std::endl;
	if (index > -1 && index < 100){
		std::cout << MAGENTA "Brain " RESET "Idea NO.:" RED << index << RESET " is set!" << std::endl;
		_ideas[index] = idea;
		return (true);
	}
	return (false);
}
std::string Brain::BgetData( int index ) const {
	std::cout << MAGENTA "Brain " RESET "getData is called!" << std::endl;
	if (index > -1 && index < 100){
		return (_ideas[index]);
	}
	return ("");
}