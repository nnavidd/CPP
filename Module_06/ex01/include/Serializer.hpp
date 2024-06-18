/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:38:21 by nnavidd           #+#    #+#             */
/*   Updated: 2024/06/18 01:59:03 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <exception>

# define BLUE		"\033[38;5;4m"
# define MAGENTA	"\033[38;5;5m"
# define CYAN		"\033[38;5;44m"
# define GREEN		"\033[38;5;2m"
# define ORG		"\033[38;5;214m"
# define RED		"\033[38;5;196m"
# define RESET		"\033[0m"

typedef struct data{
    int				i;
    std::string		str;
    float       	f;
    double      	d;
} Data;

class Serializer {
    private:
        Serializer( void );
        Serializer(Serializer const &);
        Serializer & operator=(Serializer const &);
        ~Serializer( void );
        
    public:
		static uintptr_t   serialize(Data* ptr); 
		static Data    *   deserialize(uintptr_t raw);
};
#endif