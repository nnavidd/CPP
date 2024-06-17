/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnavidd <nnavidd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:38:21 by nnavidd           #+#    #+#             */
/*   Updated: 2024/06/17 19:54:48 by nnavidd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <exception>
# include <cstdint>

typedef struct data{
    size_t      i;
    std::string str;
    float       f;
    double      d;
} Data;

class Serilizer {
    private:
        Serilizer( void ) = delete;
        Serilizer(Serilizer const &) = delete;
        Serilizer & operator=(Serilizer const &) = delete;
        ~Serilizer( void ) = delete;
        
    public:
    static uintptr_t   serialize(Data* ptr); 
    static Data    *   deserialize(uintptr_t raw);
};
#endif