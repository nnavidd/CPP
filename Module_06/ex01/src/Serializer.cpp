/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnavidd <nnavidd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:36:19 by nnavidd           #+#    #+#             */
/*   Updated: 2024/06/18 00:32:25 by nnavidd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Serializer.hpp"

Serializer::Serializer( void ){}

Serializer::Serializer(Serializer const & other){
	*this = other;
}

Serializer & Serializer::operator=(Serializer const & other){
	if(this != &other)
		*this = other;
	return (*this);
}

Serializer::~Serializer( void ){}

Data * Serializer::deserialize(unsigned long raw){
    return (reinterpret_cast<Data *>(raw));
}

unsigned long   Serializer::serialize(Data * ptr){
    return (reinterpret_cast<unsigned long>(ptr));
}
