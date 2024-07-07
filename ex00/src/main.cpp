/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnavidd <nnavidd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:47:47 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/07/07 11:31:18 by nnavidd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

bool isValidDate(std::string const & date) {
	// Check if the date is in the format YYYY-MM-DD
	if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
		std::cerr << RED "Error: " ORG "bad date structure => " RESET << date << std::endl;
		return (false);
	}

	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8, 2);

	int year = atoi(yearStr.c_str());
	int month = atoi(monthStr.c_str());
	int day = atoi(dayStr.c_str());

	if (year < 2000 || year > 9999 || month < 1 ||
		 month > 12 || day < 1 || day > 31) {
		std::cerr << RED "Error: " ORG "wrong date => " RESET << date << std::endl;
		return (false);
	}
	return (true);
}

bool isValidValue(std::string const & valueStr) {
	float value = atof(valueStr.c_str());

	if (value < 0)
		std::cerr << RED "Error: " ORG "not a positive number." RESET << std::endl;
	else if (value > 1000)
		std::cerr << RED "Error: " ORG "a too large number." RESET << std::endl;
	
	return (value >= 0 && value <= 1000);
}

bool isValidStructure(std::istringstream & ss, std::string & date, std::string & valueStr) {
	if (ss.str().find('|') == 11) {
		if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
			date = date.substr(0, date.find_last_not_of(" \t\n\r\f\v") + 1);
			valueStr = valueStr.substr(valueStr.find_first_not_of(" \t\n\r\f\v"));
			return (true);
		}
	} else
		std::cerr << RED "Error: " ORG "bad input format => " RESET << ss.str() << std::endl;
	return (false);
}

bool fetchDateValue(std::istringstream & ss, std::string & date, std::string & valueStr) {
	if (!isValidStructure(ss, date, valueStr))
		return (false);
	if (!isValidDate(date))
		return (false);
	if (!isValidValue(valueStr))
		return (false);
	return (true);
}

void runCalculation(BTC const & btc, std::string const & date, std::string const & valueStr) {
	float value;
	float rate;
	float result;

	value = atof(valueStr.c_str());
	rate = btc.getRate(date);
	result = value * rate;

	std::cout << GREEN << date << ORG " => " MAGENTA << value 
			<< ORG " = " CYAN << result << RESET << std::endl;
}	

bool readInputFile(std::ifstream & inputFile) {
	try {
		BTC btc("data.csv");
		std::string line;
		std::getline(inputFile, line); //read the first line of input to ignore it
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
