/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:42:47 by nnavidd           #+#    #+#             */
/*   Updated: 2024/06/18 01:57:37 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Serializer.hpp"

int main(){
    Data            originalData;
    Data            *deserializedData;
    uintptr_t   	raw;

    originalData.i = 4;
    originalData.str = "42 is an institute";

    raw = Serializer::serialize(&originalData);
    deserializedData = Serializer::deserialize(raw);
   
    std::cout << GREEN "raw                address: " CYAN << &raw << RESET << std::endl;
    std::cout << GREEN "originalData       address: " CYAN << &originalData << RESET << std::endl;
    std::cout << GREEN "deserializedData   address: " CYAN << deserializedData << RESET << std::endl;
    std::cout << RED "--------------------------------" RESET << std::endl;
   
    std::cout << GREEN "originalData     uintptr_t: " MAGENTA << originalData.i << RESET << std::endl;
    std::cout << GREEN "originalData        string: " MAGENTA << originalData.str << RESET << std::endl << std::endl;
    std::cout << GREEN "deserializedData uintptr_t: " MAGENTA << deserializedData->i << RESET << std::endl;
    std::cout << GREEN "deserializedData    string: " MAGENTA << deserializedData->str << RESET << std::endl; 
    std::cout << RED "--------------------------------" RESET << std::endl;
    // Create a Data object
    originalData.i = 42;
    originalData.str = "This is a test.";

    // Serialize the Data object
    raw = Serializer::serialize(&originalData);
    
    // Deserialize the raw value back to a Data pointer
    deserializedData = Serializer::deserialize(raw);

    // Verify that the deserialized pointer is the same as the original pointer
    if (deserializedData == &originalData) {
        std::cout << BLUE "Deserialization successful!" << std::endl;
        std::cout << GREEN "deserializedData int variable: " ORG << deserializedData->i << RESET << std::endl;
        std::cout << GREEN "deserializedData str variable: " ORG << deserializedData->str << RESET << std::endl;
    } else {
        std::cout << RED "Deserialization failed." RESET << std::endl;
    }

    return 0;
}
