/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 08:34:38 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/14 09:09:36 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point) {
	Fixed areaABC((b.getY() - c.getY()) * (a.getX() - c.getX())
			 	+ (c.getX() - b.getX()) * (a.getY() - c.getY()));
	
	Fixed areaBCP(((b.getY() - c.getY()) * (point.getX() - c.getX())
				+ (c.getX() - b.getX()) * (point.getY() - c.getY())) / areaABC);
	
	Fixed areaACP(((c.getY() - a.getY()) * (point.getX() - c.getX())
			 	+ (a.getX() - c.getX()) * (point.getY() - c.getY())) / areaABC);
	
	return (areaBCP > Fixed(0) && areaBCP < Fixed(1)
		 && areaACP > Fixed(0) && areaACP < Fixed(1)
		 && (Fixed(1) - areaBCP - areaACP) > Fixed(0));
}