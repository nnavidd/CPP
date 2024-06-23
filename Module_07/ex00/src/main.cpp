/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnavidd <nnavidd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:36:32 by nnavidd           #+#    #+#             */
/*   Updated: 2024/06/23 13:20:12 by nnavidd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Temp.hpp"

int main (){
	int     i1, i2;
	char    ch1, ch2;
	float   f1, f2;

	i1 = 3;
	i2 = 5;
	ch1 = 'a';
	ch2 = 'd';
	f1 = 3.2f;
	f2 = 3.3f;

	std::cout << RED "------------swap------------" RESET << std::endl;
	std::cout << GREEN "int 1: " CYAN << i1 << GREEN "	int 2: " CYAN << i2 << ORG"	after swap ->";
	swap(i1, i2);
	std::cout << GREEN "int 1: " CYAN << i1 << GREEN "		int 2: " CYAN << i2 << std::endl;
	std::cout << GREEN "char 1: " CYAN << ch1 << GREEN "	char 2: " CYAN << ch2 << ORG"	after swap ->";
	swap(ch1, ch2);
	std::cout << GREEN "char 1: " CYAN << ch1 << GREEN "		char 2: " CYAN << ch2 << std::endl;
	std::cout << GREEN "flout 1: " CYAN << f1 << GREEN "	flout 2: " CYAN << f2 << ORG"	after swap ->";
	swap(f1, f2);
	std::cout << GREEN "flout 1: " CYAN << f1 << GREEN "	flout 2: " CYAN << f2 << std::endl;

	std::cout << RED "------------min------------" RESET << std::endl;
	std::cout << GREEN "min( " CYAN<< i1<< GREEN" , " CYAN << i2 <<" ): " ORG << min(i1, i2) << std::endl;
	std::cout << GREEN "min( " CYAN<< ch1<< GREEN" , " CYAN << ch2 <<" ): " ORG << min(ch1, ch2) << std::endl;
	std::cout << GREEN "min( " CYAN<< f1<< GREEN" , " CYAN << f2 <<" ): " ORG << min(f1, f2) << std::endl;

	std::cout << RED "------------max------------" RESET << std::endl;
	std::cout << GREEN "max( " CYAN<< i1<< GREEN" , " CYAN << i2 <<" ): " ORG << max(i1, i2) << std::endl;
	std::cout << GREEN "max( " CYAN<< ch1<< GREEN" , " CYAN << ch2 <<" ): " ORG << max(ch1, ch2) << std::endl;
	std::cout << GREEN "max( " CYAN<< f1<< GREEN" , " CYAN << f2 <<" ): " ORG << max(f1, f2) << std::endl;
	return (0);
}