/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:47:47 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/07/06 13:54:47 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

bool isValidDate(const std::string& date) {
    // Check if the date is in the format YYYY-MM-DD
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') return false;

    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    int year = atoi(yearStr.c_str());
    int month = atoi(monthStr.c_str());
    int day = atoi(dayStr.c_str());

    if (year < 2000 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31) return false;

    // Further checks for days in month can be added
    return true;
}

bool isValidValue(const std::string& valueStr) {
    float value = atof(valueStr.c_str());
    return value >= 0 && value <= 1000;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
        return 1;
    }

    std::string inputFilePath = argv[1];
    std::ifstream inputFile(inputFilePath.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
	std::cout << "hi\n";
    }

    try {
        BTC btc("btc_database.csv");
        std::string line;
        while (std::getline(inputFile, line)) {
            std::istringstream ss(line);
            std::string date, valueStr;
            if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
                date = date.substr(0, date.find_last_not_of(" \t\n\r\f\v") + 1);
                valueStr = valueStr.substr(valueStr.find_first_not_of(" \t\n\r\f\v"));

                if (!isValidDate(date)) {
                    std::cerr << "Error: bad input => " << date << std::endl;
                    continue;
                }

                if (!isValidValue(valueStr)) {
                    std::cerr << "Error: invalid value." << std::endl;
                    continue;
                }

                float value = atof(valueStr.c_str());
                float rate = btc.getRate(date);
                float result = value * rate;

                std::cout << date << " => " << value << " = " << result << std::endl;
            } else {
                std::cerr << "Error: bad input format." << std::endl;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
