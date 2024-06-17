/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:36:19 by nnavidd           #+#    #+#             */
/*   Updated: 2024/06/17 20:16:03 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Serializer.hpp"

Serilizer::Serilizer( void ){}

Serilizer::Serilizer(Serilizer const & other){
	*this = other;
}

Serilizer & Serilizer::operator=(Serilizer const & other){
	if(this != &other)
		*this = other;
	return (*this);
}

Serilizer::~Serilizer( void ){}

Data * Serilizer::deserialize(uintptr_t raw){
    return (reinterpret_cast<Data *>(raw));
}

uintptr_t   Serilizer::serialize(Data * ptr){
    return (reinterpret_cast<uintptr_t>(ptr));
}
