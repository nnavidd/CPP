/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:46:50 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/07/06 13:47:37 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

// Default constructor
BTC::BTC() {}

// Constructor with file path
BTC::BTC(const std::string& dbFilePath) {
    if (!loadDatabase(dbFilePath)) {
        throw std::runtime_error("Error: could not open file.");
    }
}

// Copy constructor
BTC::BTC(const BTC& other) : btcRates(other.btcRates) {}

// Copy assignment operator
BTC& BTC::operator=(const BTC& other) {
    if (this != &other) {
        btcRates = other.btcRates;
    }
    return *this;
}

// Destructor
BTC::~BTC() {}

// Private method to load the database from a file
bool BTC::loadDatabase(const std::string& dbFilePath) {
    std::ifstream dbFile(dbFilePath.c_str());
    if (!dbFile.is_open()) return false;

    std::string line, date;
    float rate;
    while (std::getline(dbFile, line)) {
        std::istringstream ss(line);
        if (std::getline(ss, date, ',') && ss >> rate) {
            btcRates[date] = rate;
        }
    }
    return true;
}

// Private method to find the closest date in the map
std::string BTC::findClosestDate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = btcRates.lower_bound(date);
    if (it == btcRates.begin() || (it != btcRates.end() && it->first != date)) {
        --it;
    }
    return it->first;
}

// Method to get the rate for a specific date
float BTC::getRate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = btcRates.find(date);
    if (it == btcRates.end()) {
        std::string closestDate = findClosestDate(date);
        return btcRates.at(closestDate);
    }
    return it->second;
}
