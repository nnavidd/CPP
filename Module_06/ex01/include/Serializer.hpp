/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:38:21 by nnavidd           #+#    #+#             */
/*   Updated: 2024/06/17 20:11:23 by nnabaeei         ###   ########.fr       */
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
        Serilizer( void );
        Serilizer(Serilizer const &);
        Serilizer & operator=(Serilizer const &);
        ~Serilizer( void );
        
    public:
    static uintptr_t   serialize(Data* ptr); 
    static Data    *   deserialize(uintptr_t raw);
};
#endif