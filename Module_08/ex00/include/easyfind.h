/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:46:47 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/30 14:43:14 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_H
# define EASY_FIND_H

# define BLUE		"\033[38;5;4m"
# define MAGENTA	"\033[38;5;5m"
# define CYAN		"\033[38;5;44m"
# define GREEN		"\033[38;5;2m"
# define ORG		"\033[38;5;214m"
# define RED		"\033[38;5;196m"
# define RESET		"\033[0m"

# include <iostream>
# include <stdexcept> // for std::out_of_range exception
# include <list>
# include <vector>
# include <iterator>
# include <algorithm>

template <typename T>
void showContainer(T &container) {
	typename T::iterator itr = container.begin();
	std::cout << "Container elements: {";
	for (;itr != container.end(); itr++) {
		std::cout << ORG << *itr << RESET;
		typename T::iterator nextitr = itr;
		++nextitr;
		if (nextitr != container.end())
			std::cout << ", ";
	}
	std::cout << "}" << std::endl;
}

class Error: public std::exception {
	public:
		const char *what() const throw() {
			return (ORG "doesn't exist in this container!!!" RESET);
		}
};

template <typename T>
typename T::iterator easyfind(T &container, int val) {
	typename T::iterator itr = std::find(container.begin(), container.end(), val);
	if (itr == container.end()) {
		std::cout << RED "The value " CYAN << val << RESET ": ";
		throw Error();
	}
	return (itr);
}

#endif