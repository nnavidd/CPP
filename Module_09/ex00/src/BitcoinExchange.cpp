/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:46:50 by nnabaeei          #+#    #+#             */
/*   Updated: 2025/05/12 09:52:20 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

BTC::BTC() {}

// Constructor with file path
BTC::BTC( std::string const & dbFilePath ) {
	if (!loadDatabase(dbFilePath)) {
		throw std::runtime_error( RED "Error: " ORG "could not open file." RESET);
	}
}

//Copy constructor
BTC::BTC( BTC const & other ) : btcRates(other.btcRates) {}

//Copy assignment oprator
BTC & BTC::operator=( BTC const & other) {
	if (this != &other) {
		btcRates = other.btcRates;
	}
	return (*this);
}

//Deconstructor
BTC::~BTC() {}

// Private method to load the database from a file
bool BTC::loadDatabase(const std::string& dbFilePath) {
    std::ifstream dbFile(dbFilePath.c_str());
    
    if (!dbFile.is_open()) {
        throw std::runtime_error(RED "Error: " ORG "could not open database file: " RESET + dbFilePath);
    }
    
    // Check if file is empty
    if (dbFile.peek() == std::ifstream::traits_type::eof()) {
        throw std::runtime_error(RED "Error: " ORG "database file is empty: " RESET + dbFilePath);
    }
    
    std::string line;
    std::string date;
    float rate;
    int lineNum = 0;
    
	std::cout << MAGENTA "\n================Check Database=================" RESET << std::endl;

    // Process the file line by line
    while (std::getline(dbFile, line)) {
        lineNum++;
        
        // Skip empty lines
        if (line.find_first_not_of(" \t\n\r\f\v") == std::string::npos)
            continue;
            
        // Skip header on first line
        if (lineNum == 1 && line.find("date") != std::string::npos)
            continue;
        
        std::istringstream ss(line);
        
        // Parse date and rate
        if (std::getline(ss, date, ',') && ss >> rate) {
            // Trim whitespace from date
            date.erase(0, date.find_first_not_of(" \t\n\r\f\v"));
            date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);
            
            // Validate date format
            if (!isValidDate(date)) {
                std::cerr << CYAN "	Warning: " ORG "skipping invalid date in database at line: " RESET << lineNum << std::endl;
                continue;
            }
            
            // Store in map
            btcRates[date] = rate;
        } else {
            std::cerr << CYAN "Warning: " ORG "invalid format in database at line: " RESET << lineNum << std::endl;
        }
    }
    
    // Check if we loaded any data
    if (btcRates.empty()) {
        throw std::runtime_error(RED "Error: " ORG "no valid data found in database file" RESET);
    }
    
    return true;
}

// Private method to find the closest date in the map
std::string BTC::findClosestDate(std::string const & date) const {
    // Handle empty database
    if (btcRates.empty()) {
        throw std::runtime_error(RED "Error: " ORG "database is empty." RESET);
    }

    // Find the first entry that is not less than the date (equal or greater)
    std::map<std::string, float>::const_iterator it = btcRates.lower_bound(date);
    
    // Case 1: Exact match found
    if (it != btcRates.end() && it->first == date) {
        return it->first;
    }
    
    // Case 2: The date is before any in our database
    if (it == btcRates.begin()) {
        std::string msg = RED "Error: " ORG "no earlier date found in database => " RESET + date;
        throw std::runtime_error(msg);
    }
    
    // Case 3: Date is after some entries in our database
    // Use the previous date (lower date)
    --it;
    return it->first;
}

// Method to get the rate for a specific date
float BTC::getRate(std::string const & date) const {
    // First try direct lookup
    std::map<std::string, float>::const_iterator it = btcRates.find(date);
    
    if (it != btcRates.end()) {
        // Case 1: Exact match found
        return it->second;
    }
    
    try {
        // Case 2: Find closest earlier date
        std::string closestDate = findClosestDate(date);
        return btcRates.at(closestDate);
    } catch (const std::exception& e) {
        // Re-throw with additional context if needed (just for learning purposes)
        throw; 
    }
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

// 
bool readInputFile(std::ifstream& inputFile) {
    try {
		// peek() looks at the next character in the stream without extracting it.
		// If the file is empty, peek() returns EOF.
        if (inputFile.peek() == std::ifstream::traits_type::eof()) {
            std::cerr << RED "Error: " ORG "input file is empty." RESET << std::endl;
            return false;
        }
        
        BTC btc("data.csv");
        std::string line;
        
        // Check header
        std::getline(inputFile, line);
        std::string trimmedHeader = line;
        trimmedHeader.erase(0, trimmedHeader.find_first_not_of(" \t\n\r\f\v"));
        trimmedHeader.erase(trimmedHeader.find_last_not_of(" \t\n\r\f\v") + 1);
        
		// std::cout << GREEN "Header: " ORG << trimmedHeader << RESET << std::endl;

        if (trimmedHeader != "date | value") {
            std::cerr << RED "Error: " ORG "invalid input file header => " RESET << line << std::endl;
            return false;
        }
        
		std::cout << MAGENTA "\n================Check Input=================" RESET << std::endl;
        // Process data lines
        while (std::getline(inputFile, line)) {
            // Skip empty lines
            if (line.find_first_not_of(" \t\n\r\f\v") == std::string::npos)
                continue;
                
            std::istringstream ss(line);
            std::string date, valueStr;
            
            if (fetchDateValue(ss, date, valueStr))
                runCalculation(btc, date, valueStr);
        }
        
        return true;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
}