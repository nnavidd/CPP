/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 08:23:06 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/14 09:22:53 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include <cstdio>
#include "Fixed.hpp"

class Point{
	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point();
		Point(float const a, float const b);
		Point(Point const & other); //copy constructor
		~Point();
		Point & operator=(Point const & other); //copy assignment

		Fixed getX( void ) const;
		Fixed getY( void ) const;
};

std::ostream & operator<<(std::ostream & out, Point const & other);
bool bsp( Point const a, Point const b, Point const c, Point const point);