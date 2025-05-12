/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:47:47 by nnabaeei          #+#    #+#             */
/*   Updated: 2025/05/12 10:28:34 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>

// // this function checks the input
bool checkInput(int argc, char** argv, std::ifstream& inputFile) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
        return false;
    }

    std::string inputPath = argv[1];

    struct stat sb;
    // stat() is used to get the status of the file (e.g., file type, permissions, size, etc.)
	// it returns 0 on success and -1 on error
	if (stat(inputPath.c_str(), &sb) != 0) {
        std::cerr << RED "Error: " ORG "file does not exist or cannot be accessed: " RESET << inputPath << std::endl;
        return false;
    }

	// S_ISDIR() checks if the file is a directory, it returns true if it is
    if (S_ISDIR(sb.st_mode)) {
        std::cerr << RED "Error: " ORG "path is a directory, not a file: " RESET << inputPath << std::endl;
        return false;
    }

	// access() is used to check the file's permissions according to second argument, it returns 0 on success
    if (access(inputPath.c_str(), R_OK) != 0) {
        std::cerr << RED "Error: " ORG "file is not readable or lacks permission: " RESET << inputPath << std::endl;
        return false;
    }

    inputFile.open(inputPath.c_str());
    if (!inputFile.is_open()) {
        std::cerr << RED "Error: " ORG "could not open file for reading: " RESET << inputPath << std::endl;
        return false;
    }

    return true;
}


int main(int argc, char* argv[]) {
	std::ifstream	inputFile;

	if (checkInput(argc, argv, inputFile) == true) {
		if (readInputFile(inputFile) == false)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);

}
