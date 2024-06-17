/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:17:47 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/17 14:34:19 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << RED "Error: " ORG "Usage-> " << argv[0] << " <literal>" RESET << std::endl;
        return 1;
    }
	try{
		ScalarConverter::convert(argv[1]);
	} catch(std::exception& worong){
		std::cout << RED "Error: " RESET<< worong.what() << std::endl;
	}

    return 0;
}
