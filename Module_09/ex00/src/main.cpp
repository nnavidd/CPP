/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:47:47 by nnabaeei          #+#    #+#             */
/*   Updated: 2025/05/11 00:12:14 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

/*iss.eof(): Checks if the end of the stream has been reached (no trailing characters).
!iss.fail(): Checks if the conversion failed (e.g., due to invalid format).*/
// this function checks if the value is a positive number
bool isValidValue(std::string const & valueStr) {

	// Trim leading and trailing whitespace
    std::string trimmed = valueStr;
    trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r\f\v"));
    trimmed.erase(trimmed.find_last_not_of(" \t\n\r\f\v") + 1);
    	
    // Check if empty after trim
    if (trimmed.empty()) {
        std::cerr << RED "Error: " ORG "empty value" RESET << std::endl;
        return false;
    }
    
    // Check if valid float format
    std::istringstream iss(trimmed);
    float value;
    iss >> value;
    
    if (!(iss.eof() && !iss.fail())) {
        std::cerr << RED "Error: " ORG "value not a number => " RESET << valueStr << std::endl;
        return false;
    }
    
    // Check range
    try {
        value = std::stof(trimmed);
        if (value < 0) {
            std::cerr << RED "Error: " ORG "not a positive number => " RESET << value << std::endl;
            return false;
        }
        if (value > 1000) {
            std::cerr << RED "Error: " ORG "too large a number => " RESET << value << std::endl;
            return false;
        }
    } catch (const std::exception& e) {
        std::cerr << RED "Error: " ORG "failed to convert value => " RESET << valueStr << std::endl;
        return false;
    }
    
    return true;
}

// this function checks if the date is in the format YYYY-MM-DD
bool isValidDate(std::string const & date) {
	// Check if the date is in the format YYYY-MM-DD
	if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
		std::cerr << RED "Error: " ORG "bad date structure => " RESET << date << std::endl;
		return (false);
	}

	// Extract year, month, and day parts
	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8, 2);

	// Check if all parts are numeric
    for (char c : yearStr + monthStr + dayStr) {
        if (!std::isdigit(c)) {
            std::cerr << RED "Error: " ORG "date contains non-numeric characters => " RESET << date << std::endl;
            return (false);
        }
    }

	try {
		int year = atoi(yearStr.c_str());
		int month = atoi(monthStr.c_str());
		int day = atoi(dayStr.c_str());

		if (year < 2009 || year > 9999) {
            std::cerr << RED "Error: " ORG "year out of range => " RESET << date << std::endl;
            return false;
        }
		if (month < 1 || month > 12) {
            std::cerr << RED "Error: " ORG "invalid month => " RESET << date << std::endl;
            return false;
        }
        if (day < 1) {
            std::cerr << RED "Error: " ORG "invalid day => " RESET << date << std::endl;
            return false;
        }
		// Add month-specific day validation
		int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		
		// Adjust February for leap years
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
			daysInMonth[2] = 29;
			
		if (day > daysInMonth[month]) {
			std::cerr << RED "Error: " ORG "invalid day for month => " RESET << date << std::endl;
			return false;
		}
	}  catch (const std::exception& e) {
        std::cerr << RED "Error: " ORG "failed to parse date => " RESET << date << std::endl;
        return false;
    }
	
	return (true);
}

// this function checks if the input line has the correct structure
// it checks if the line has a pipe and if the date and value are not empty
bool isValidStructure(std::istringstream& ss, std::string& date, std::string& valueStr) {
    std::string line = ss.str();
    if (line.empty()) {
		std::cerr << RED "Error: " ORG "empty line" RESET << std::endl;
		return false;
	}
	size_t pipePos = line.find('|');
    
    // Check if pipe exists
    if (pipePos == std::string::npos) {
        std::cerr << RED "Error: " ORG "missing separator '|' => " RESET << line << std::endl;
        return false;
    }
    
    // Extract date and value parts
    date = line.substr(0, pipePos);
    valueStr = line.substr(pipePos + 1);
    
    // Trim whitespace
    date.erase(0, date.find_first_not_of(" \t\n\r\f\v"));
    date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);
    
    valueStr.erase(0, valueStr.find_first_not_of(" \t\n\r\f\v"));
    valueStr.erase(valueStr.find_last_not_of(" \t\n\r\f\v") + 1);
    
    // Check if both parts exist after trimming
    if (date.empty()) {
        std::cerr << RED "Error: " ORG "missing date => " RESET << line << std::endl;
        return false;
    }
    if (valueStr.empty()) {
        std::cerr << RED "Error: " ORG "missing value => " RESET << line << std::endl;
        return false;
    }
    
    return true;
}

// this function checks if the date and value are valid
bool fetchDateValue(std::istringstream & ss, std::string & date, std::string & valueStr) {
	if (!isValidStructure(ss, date, valueStr))
		return (false);
	if (!isValidDate(date))
		return (false);
	if (!isValidValue(valueStr))
		return (false);
	return (true);
}

// this function calculates the result
void runCalculation(BTC const & btc, std::string const & date, std::string const & valueStr) {
	float value;
	float rate;
	float result;

	value = atof(valueStr.c_str());
	try {
		rate = btc.getRate(date);
		result = value * rate;

		std::cout << GREEN << date << ORG " => " MAGENTA << value 
				<< ORG " = " CYAN << result << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return;
	}
}	

// this function reads the input file
bool readInputFile(std::ifstream & inputFile) {
	try {
		BTC btc("data.csv");
		std::string line;
		std::getline(inputFile, line); //read the first line of input to check the header
		if (line != "date | value")
        	throw std::runtime_error( RED "Error: " ORG "invalid input file header." RESET);
		while (std::getline(inputFile, line)) {
			std::istringstream ss(line);
			std::string date, valueStr;
			if (fetchDateValue(ss, date, valueStr) == true)
				runCalculation(btc, date, valueStr);
			else
				continue;
		}
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (false);
	}
	return (true);
}

// this function checks the input
bool checkInput(int ac, char **av, std::ifstream & inputFile) {
	if (ac != 2) {
		std::cerr << GREEN "Usage: " ORG << av[0] << MAGENTA " <input file>" RESET << std::endl;
		return (false);
	}
	std::string inputFilePath = av[1];
	inputFile.open(inputFilePath.c_str());
	if (!inputFile.is_open()) {
		std::cerr << RED "Error: " ORG "could not open file." RESET << std::endl;
		return (false);
	}
	return (true);
}

int main(int argc, char* argv[]) {
	std::ifstream	inputFile;

	if (checkInput(argc, argv, inputFile) == true) {
		if (readInputFile(inputFile) == false)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);

}
