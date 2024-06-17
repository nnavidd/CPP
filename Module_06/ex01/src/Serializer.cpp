/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnavidd <nnavidd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:36:19 by nnavidd           #+#    #+#             */
/*   Updated: 2024/06/17 19:54:05 by nnavidd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Serializer.hpp"

Data * Serilizer::deserialize(uintptr_t raw){
    return (reinterpret_cast<Data *>(raw));
}

uintptr_t   Serilizer::serialize(Data * ptr){
    return (reinterpret_cast<uintptr_t>(ptr));
}
