/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:51:31 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/09 20:58:47 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

void	check(float ax, float ay, float bx, float by, float cx, float cy, float ptx, float pty){
	Point	a(ax, ay);
	Point	b(bx, by);
	Point	c(cx, cy);
	Point	pt(ptx, pty);

	std::cout << BLUE "▲: " GREEN "a" ORG<< a << GREEN " b" ORG<< b << GREEN " c" ORG << c << RED" ? " GREEN "point" ORG << pt << 
	" " << (bsp(a, b, c, pt) ? "✅" : "❌") << RESET << std::endl;
}

int main(int ac, char **av) {
	Point a(1, 1);
	Point b(4, 1);
	Point c(2, 5);
	Point testPoint(4, 5);

	if (bsp(a, b, c, testPoint)) {
		std::cout << GREEN "The point is inside the triangle." RESET << std::endl;
		std::cout << BLUE "▲: " GREEN "a" ORG<< a << GREEN " b" ORG<< b << GREEN " c" ORG << c << RED" ? " GREEN "point" ORG << testPoint << " " << (bsp(a, b, c, testPoint) ? "✅" : "❌") << RESET << std::endl;
	} else {
		std::cout << BLUE "▲: " GREEN "a" ORG<< a << GREEN " b" ORG<< b << GREEN " c" ORG << c << RED" ? " GREEN "point" ORG << testPoint << " " << (bsp(a, b, c, testPoint) ? "✅" : "❌") << RESET << std::endl;
		std::cout << GREEN "The point is outside the triangle." RESET << std::endl;
	}

	if(ac == 2 && av[1][0] == '!'){
		check(93, 2, 2, 72, 70, 81, 44, 68); //inside -> ✅
		check(93, 2, 2, 72, 70, 81, 5, 72); // near edge -> ✅
		check(93, 2, 2, 72, 70, 81, 47.5f, 37); // on edge -> ❌
		check(93, 2, 2, 72, 70, 81, 2, 72); // is vertex -> ❌
		check(93, 2, 2, 72, 70, 81, -2, 72); // outside -> ❌
		std::cout << std::endl;
		check(14, 63, 39, 97, 56, 75, 43, 80); //inside -> ✅
		check(14, 63, 39, 97, 56, 75, 33, 69); // near edge -> ✅
		check(14, 63, 39, 97, 56, 75, 45.8, 88.2); // on edge -> ❌
		check(14, 63, 39, 97, 56, 75, 14, 63); // is vertex -> ❌
		check(14, 63, 39, 97, 56, 75, 50, 50); // outside -> ❌
		std::cout << std::endl;
		check(5, 88, 8, 95, 94, 13, 19, 81); //inside -> ✅
		check(5, 88, 8, 95, 94, 13, 66, 39); // near edge -> ✅
		check(5, 88, 8, 95, 94, 13, 13.9, 80.1); // on edge -> ❌
		check(5, 88, 8, 95, 94, 13, 94, 13); // is vertex -> ❌
		check(5, 88, 8, 95, 94, 13, 13, 15); // outside -> ❌
	}
	return 0;
}
