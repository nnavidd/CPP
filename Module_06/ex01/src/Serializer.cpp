/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:36:19 by nnavidd           #+#    #+#             */
/*   Updated: 2024/06/18 01:43:14 by nnabaeei         ###   ########.fr       */
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

Data * Serializer::deserialize(uintptr_t raw){
    return (reinterpret_cast<Data *>(raw));
}

uintptr_t   Serializer::serialize(Data * ptr){
    return (reinterpret_cast<uintptr_t>(ptr));
}
