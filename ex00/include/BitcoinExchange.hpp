/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnavidd <nnavidd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:43:12 by nnabaeei          #+#    #+#             */
/*   Updated: 2025/01/14 09:11:55 by nnavidd          ###   ########.fr       */
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

// it has a constructor that takes a file path as an argument,
// and the exchange rates loaded from the file in a map
class BTC {
	private:
		std::map<std::string, float> btcRates;

		// Private method to load the database from a file
		bool loadDatabase( std::string const & dbFilePath );

		// Private method to find the closest date in the map
		std::string findClosestDate( std::string const & date ) const;
	public:
		// Default constructor
		BTC();

		// Constructor with file path
		BTC( std::string const & dbFilePath );

		// Copy constructor
		BTC( BTC const & other );

		// Copy assignment operator
		BTC & operator=( BTC const & other );

		// Destructor
		~BTC();

		// Method to get the rate for a specific date
		float getRate( std::string const & date ) const;
};

#endif

