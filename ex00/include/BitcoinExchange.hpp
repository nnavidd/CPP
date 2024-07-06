/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:43:12 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/07/06 13:49:35 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


# define BLUE		"\033[38;5;4m"
# define MAGENTA	"\033[38;5;5m"
# define CYAN		"\033[38;5;44m"
# define GREEN		"\033[38;5;2m"
# define ORG		"\033[38;5;214m"
# define RED		"\033[38;5;196m"
# define RESET		"\033[0m"


#include <iostream>
#include <string>
#include <map>
#include <limits>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

class BTC {
	private:
		std::map<std::string, float> btcRates;

		// Private method to load the database from a file
		bool loadDatabase(const std::string& dbFilePath);

		// Private method to find the closest date in the map
		std::string findClosestDate(const std::string& date) const;
	public:
		// Default constructor
		BTC();

		// Constructor with file path
		BTC(const std::string& dbFilePath);

		// Copy constructor
		BTC(const BTC& other);

		// Copy assignment operator
		BTC& operator=(const BTC& other);

		// Destructor
		~BTC();

		// Method to get the rate for a specific date
		float getRate(const std::string& date) const;
};

#endif // BTC_HPP

