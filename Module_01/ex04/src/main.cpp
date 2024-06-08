/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:52:13 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/08 10:03:22 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int ac, char **av)
{
	std::string		text = "";
	size_t			pos;

	if (ac == 4)
	{
		std::ifstream	in(av[1]);
		if (!in.is_open())
			return (std::cout << "Opening the source is not possible!" << std::endl, 1);
		
		std::getline(in, text, '\0');
		
		while ((pos = text.find(av[2])) != std::string::npos)
		{
			text.erase(pos, std::string(av[2]).length());
			text.insert(pos, av[3]);
		}
		
		std::ofstream	ou((std::string(av[1]) + ".replace").c_str());
		if (!ou.is_open())
			return (std::cout << "Opening the destinaiton is not possible!!" << std::endl, 1);
		
		ou << text;
		
		in.close();
		ou.close();
	}
	return (0);
}
