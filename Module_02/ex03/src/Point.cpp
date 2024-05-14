/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 08:35:45 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/14 09:27:11 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

Point::Point(): _x(0), _y(0){}
Point::Point(float const a, float const b): _x(a), _y(b){}
Point::Point(Point const & other):_x(other.getX()), _y(other.getY()){}
Point & Point::operator=(Point const & other){
	if (this != &other){
		( Fixed ) this->_x = other.getX();
		( Fixed ) this->_y = other.getY();
	}
	return (*this);

//second method to 
	this->~Point();
	new(this) Point(other);
	return (*this);
}
Point::~Point( void ){}

Fixed	Point::getX( void ) const{
	return (_x);
}

Fixed	Point::getY( void ) const{
	return (_y);
}

std::ostream & operator<<(std::ostream & out, const Point & other){
    out << "(" << other.getX() << " , " << other.getY() << ")";
    return out;
}
