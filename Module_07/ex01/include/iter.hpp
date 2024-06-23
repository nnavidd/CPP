/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:24:59 by nnavidd           #+#    #+#             */
/*   Updated: 2024/06/23 19:22:43 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP


# define BLUE		"\033[38;5;4m"
# define MAGENTA	"\033[38;5;5m"
# define CYAN		"\033[38;5;44m"
# define GREEN		"\033[38;5;2m"
# define ORG		"\033[38;5;214m"
# define RED		"\033[38;5;196m"
# define RESET		"\033[0m"

# include <iostream>
# include <string>

/*Implement a function template iter that takes 3 parameters and returns nothing.
• The first parameter is the address of an array.
• The second one is the length of the array. 
• The third one is a function that will be called on every element of the array. 
Turn in a main.cpp file that contains your tests. 
Provide enough code to generate a test executable. 
Your iter function template must work with any type of array.
The third parameter can be an instantiated function template.*/
template <typename T>
void	incFunc(T & num) {
	num++;
}

template <typename T>
void	printMemberArray(T * arr, std::size_t size, std::string info) {
	std::cout << GREEN "The array " RED << info << GREEN " calling incFunc: { " ORG ;
	for (int i = 0; i < static_cast<int>(size); i++) {
		std::cout << arr[i] << " " ;
	}
	std::cout << GREEN "}" RESET << std::endl;
}

template <typename T>
void	printStringArray(T const & elem) {
	std::cout << ORG << elem << RESET " ";
}


template <typename T, typename Func>
void	iter(T *arr, std::size_t lentgh, Func func){
	for (int i = 0; i < static_cast<int>(lentgh); ++i)
		func(arr[i]);
}

#endif