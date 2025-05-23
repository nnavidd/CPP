/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:27:50 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/04/27 09:28:01 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	print_upper(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		for (int j = 0; av[i][j]; j++)
		{
			char c = std::toupper(av[i][j]);
			std::cout << c;
		}
	}
	std::cout << std::endl;
	return (0);
}

int	main(int ac, char **av)
{
	if (ac >= 2)
		return (print_upper(ac, av));
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (1);
}