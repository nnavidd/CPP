/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:46:50 by nnabaeei          #+#    #+#             */
/*   Updated: 2025/05/07 12:23:34 by nnabaeei         ###   ########.fr       */
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
bool BTC::loadDatabase( std::string const & dbFilePath ) {
	std::string		line;
	std::string		date;
	float 			rate;
	std::ifstream	dbFile;

	dbFile.open(dbFilePath.c_str());
	if (!dbFile.is_open())
		throw std::runtime_error( RED "Error: " ORG "could not open db file." RESET);

	while (std::getline(dbFile, line)) {
		std::istringstream ss(line);
		if (std::getline(ss, date, ',') && ss >> rate) {
			btcRates[date] = rate;
			if (rate < 0) {
				std::cerr << RED "Error: " ORG "Negative rate found for date: " << date << RESET << std::endl;
				return (false);
			}
		}
	}
	return (true);
}

// Private method to find the closest date in the map
std::string BTC::findClosestDate( std::string const & date ) const {
	std::map<std::string, float>::const_iterator it = btcRates.lower_bound(date);
	// if (it == btcRates.begin() && it->first != date) {
		// throw std::runtime_error("No available rate before the given date.");
		if (it == btcRates.begin() && it->first != date) {
			return ("");
		}
	if (it->first != date) {
		--it;
	}
	return (it->first);
}

// Method to get the rate for a specific dat
float BTC::getRate( std::string const & date ) const {
	std::map<std::string, float>::const_iterator it = btcRates.find(date);
	if (it == btcRates.end()) {
		std::string closestDate = findClosestDate(date);
		if (closestDate.empty()) {
			std::string errorMsg = ORG "No available rate before the given date => " RESET + date;
			throw std::runtime_error(errorMsg);
		}
		return (btcRates.at(closestDate));
	}
	return (it->second);
}
