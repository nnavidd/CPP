/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnavidd <nnavidd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:42:47 by nnavidd           #+#    #+#             */
/*   Updated: 2024/06/18 01:09:36 by nnavidd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Serializer.hpp"

int main(){
    Data            originalData;
    Data            *deserializedData;
    unsigned long   raw;

    originalData.i = 4;
    originalData.str = "42 is an institute";

    raw = Serializer::serialize(&originalData);
    deserializedData = Serializer::deserialize(raw);
   
    std::cout << GREEN "raw              address:   " RESET << &raw << std::endl;
    std::cout << GREEN "originalData     address:   " RESET << &originalData << std::endl;
    std::cout << GREEN "deserializedData address:   " RESET << deserializedData << std::endl;
    std::cout << "--------------------------------" << std::endl;
   
    std::cout << GREEN "originalData     unsigned long: " MAGENTA << originalData.i << RESET << std::endl;
    std::cout << GREEN "originalData            string: " MAGENTA << originalData.str << RESET << std::endl << std::endl;
    std::cout << GREEN "deserializedData unsigned long: " MAGENTA << deserializedData->i << RESET << std::endl;
    std::cout << GREEN "deserializedData        string: " MAGENTA << deserializedData->str << RESET << std::endl; 
    std::cout << "--------------------------------" << std::endl;
    // Create a Data object
    originalData.i = 42;
    originalData.str = "This is a test.";

    // Serialize the Data object
    raw = Serializer::serialize(&originalData);
    
    // Deserialize the raw value back to a Data pointer
    deserializedData = Serializer::deserialize(raw);

    // Verify that the deserialized pointer is the same as the original pointer
    if (deserializedData == &originalData) {
        std::cout << GREEN "Deserialization successful!" << std::endl;
        std::cout << GREEN "Data i  : " ORG << deserializedData->i << RESET << std::endl;
        std::cout << GREEN "Data str: " ORG << deserializedData->str << RESET << std::endl;
    } else {
        std::cout << RED "Deserialization failed." RESET << std::endl;
    }

    return 0;
}
