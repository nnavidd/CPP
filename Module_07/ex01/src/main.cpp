/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnavidd <nnavidd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:32:18 by nnavidd           #+#    #+#             */
/*   Updated: 2024/06/23 13:51:35 by nnavidd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"

// Example function to be called on each element
template <typename T>
void printElement(T const & element) {
    std::cout << element << " ";
}

// Another example function to increment each element
template <typename T>
void incrementElement(T& element) {
    ++element;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    std::size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original int array: ";
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl;

    std::cout << "Incrementing elements in int array..." << std::endl;
    iter(intArray, intArrayLength, incrementElement<int>);

    std::cout << "Modified int array: ";
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl;

    std::string strArray[] = {"hello", "world", "test"};
    std::size_t strArrayLength = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "Original string array: ";
    iter(strArray, strArrayLength, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}
