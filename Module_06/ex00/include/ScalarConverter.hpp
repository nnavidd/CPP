/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:01:28 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/17 14:08:43 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTOR_HPP
# define SCALARCONVERTOR_HPP

# include <iostream>
# include <string>
# include <exception>
# include <sstream>
# include <limits>
# include <climits>
# include <iomanip>
# include <cmath>
# include <cstdio>
# include <cstdlib>

# define BLUE		"\033[38;5;4m"
# define MAGENTA	"\033[38;5;5m"
# define CYAN		"\033[38;5;44m"
# define GREEN		"\033[38;5;2m"
# define ORG		"\033[38;5;214m"
# define RED		"\033[38;5;196m"
# define RESET		"\033[0m"

class ScalarConverter{
	private:
		
		ScalarConverter( void );
		ScalarConverter(const ScalarConverter &);
		ScalarConverter &operator=(const ScalarConverter &);
		~ScalarConverter( void );

		static void detectType(const std::string &literal, bool &isChar, bool &isInt, bool &isFloat, bool &isDouble, char &c, int &i, float &f, double &d);
		static void handleSpecialCases(const std::string &literal, bool &isFloat, bool &isDouble, float &f, double &d);
		static void tryConvertToInt(const std::string &literal, bool &isInt, int &i);
		static void tryConvertToFloatOrDouble(const std::string &literal, bool &isFloat, bool &isDouble, float &f, double &d);
		static void printResults(bool isChar, bool isInt, bool isFloat, bool isDouble, char c, int i, float f, double d);
		static void printChar(char c);
		static void printInt(int i);
		static void printFloat(float f);
		static void printDouble(double d);
		static void printCharFromInt(int i);
		static void printCharFromFloat(float f);
		static void printCharFromDouble(double d);
		static void printIntFromFloat(float f);
		static void printIntFromDouble(double d);
		static void printFloatFromChar(char c);
		static void printDoubleFromChar(char c);
		static void printFloatFromInt(int i);
		static void printDoubleFromInt(int i);
		static void printFloatFromDouble(double d);

	public:
		static void convert(std::string const & literal);

		class worng : public std::exception{
			virtual const char* what() const throw();
		};
};

#endif