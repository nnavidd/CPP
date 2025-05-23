/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:15:50 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/17 14:33:09 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    static_cast<void>(other);
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    if (this != &other)
		static_cast<void>(other);
    return (*this);
}

ScalarConverter::~ScalarConverter(void) {}

const char * ScalarConverter::worng::what() const throw(){
	return (ORG "Unknown <literal> format" RESET);
}

void ScalarConverter::convert(const std::string &literal) {
	char c = 0;
	int i = 0;
	float f = 0.0f;
	double d = 0.0;
	bool isChar = false, isInt = false, isFloat = false, isDouble = false;

	detectType(literal, isChar, isInt, isFloat, isDouble, c, i, f, d);
	printResults(isChar, isInt, isFloat, isDouble, c, i, f, d);
}

void ScalarConverter::detectType(const std::string &literal, bool &isChar, bool &isInt, bool &isFloat, bool &isDouble, char &c, int &i, float &f, double &d) {
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
		c = literal[0];
		isChar = true;
	} else {
		handleSpecialCases(literal, isFloat, isDouble, f, d);
		if (!isFloat && !isDouble) {
			tryConvertToInt(literal, isInt, i);
			if (!isInt) {
				tryConvertToFloatOrDouble(literal, isFloat, isDouble, f, d);
			}
		}
	}
}

void ScalarConverter::handleSpecialCases(const std::string &literal, bool &isFloat, bool &isDouble, float &f, double &d) {
	if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
		isFloat = true;
		if (literal == "nanf") f = std::numeric_limits<float>::quiet_NaN();
		else if (literal == "+inff") f = std::numeric_limits<float>::infinity();
		else if (literal == "-inff") f = -std::numeric_limits<float>::infinity();
	} else if (literal == "nan" || literal == "+inf" || literal == "-inf") {
		isDouble = true;
		if (literal == "nan") d = std::numeric_limits<double>::quiet_NaN();
		else if (literal == "+inf") d = std::numeric_limits<double>::infinity();
		else if (literal == "-inf") d = -std::numeric_limits<double>::infinity();
	}
}

void ScalarConverter::tryConvertToInt(const std::string &literal, bool &isInt, int &i) {
	char *end;
	long l = strtol(literal.c_str(), &end, 10);
	if (*end == '\0' && (l > std::numeric_limits<int>::min() && l < std::numeric_limits<int>::max())){
		i = static_cast<int>(l);
		isInt = true;
	} 
}

void ScalarConverter::tryConvertToFloatOrDouble(const std::string &literal, bool &isFloat, bool &isDouble, float &f, double &d) {
	char *end;
	f = strtof(literal.c_str(), &end);
	if (*end == 'f' && *(end + 1) == '\0') {
		isFloat = true;
	} else {
		d = strtod(literal.c_str(), &end);
		if (*end == '\0') {
			isDouble = true;
		}
	}
}

void ScalarConverter::printResults(bool isChar, bool isInt, bool isFloat, bool isDouble, char c, int i, float f, double d) {
	// printf("i:%d , f:%d , d:%d, c:%d\n", isInt, isFloat, isDouble, isChar);
	// try{
		if (isChar) {
			printChar(c);
			printInt(static_cast<int>(c));
			printFloat(static_cast<float>(c));
			printDouble(static_cast<double>(c));
		} else if (isInt) {
			printCharFromInt(i);
			printInt(i);
			printFloatFromInt(i);
			printDoubleFromInt(i);
		} else if (isFloat) {
			printCharFromFloat(f);
			printIntFromFloat(f);
			printFloat(f);
			printDouble(static_cast<double>(f));
		} else if (isDouble) {
			printCharFromDouble(d);
			printIntFromDouble(d);
			printFloatFromDouble(d);
			printDouble(d);
		} else {
			throw ScalarConverter::worng();
		}
	// } catch (std::exception& wrong){
	// 	std::cout << "Error:" << wrong.what() << std::endl;
	// }
}

void ScalarConverter::printChar(char c) {
	if (std::isprint(c))
		std::cout << CYAN "char:	" RESET "'" GREEN << c << RESET "'" << std::endl;
	else
		std::cout << CYAN "char:	" GREEN "Non displayable" RESET << std::endl;
}

void ScalarConverter::printInt(int i) {
	// if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max())
	if (i > -2147483648 || i < 2147483647){

		std::cout << MAGENTA "int:	" GREEN << i << RESET <<std::endl;
	}
	else
		std::cout << "int: impossible" << std::endl;
}

void ScalarConverter::printFloat(float f) {
	std::cout << std::fixed << std::setprecision(1);
	if (f == std::numeric_limits<float>::infinity())
		std::cout << ORG "float:	" GREEN "+inff" << std::endl;
	else if (f == -std::numeric_limits<float>::infinity())
		std::cout << ORG "float:	" GREEN "-inff" << std::endl;
	else if (std::isnan(f))
		std::cout << ORG "float:	" GREEN "nanf" << std::endl;
	else{
			if (f < -std::numeric_limits<float>::max() || f > std::numeric_limits<float>::max())
				std::cout << ORG "float:	" GREEN "impossible" RESET << std::endl;
			else 
				std::cout << ORG "float:	" GREEN << static_cast<float>(f) << "f" RESET << std::endl;
	}
		// std::cout << ORG "float:	" GREEN << f << "f" RESET << std::endl;
}

void ScalarConverter::printDouble(double d) {
	std::cout << std::fixed << std::setprecision(1);
	if (d == std::numeric_limits<double>::infinity())
		std::cout << BLUE "double:	" GREEN "+inf" << std::endl;
	else if (d == -std::numeric_limits<double>::infinity())
		std::cout << BLUE "double:	" GREEN "-inf" << std::endl;
	else if (std::isnan(d))
		std::cout << BLUE "double:	" GREEN "nan" << std::endl;
	else
		std::cout << BLUE "double:	" GREEN << d << RESET << std::endl;
}

void ScalarConverter::printCharFromInt(int i) {
	if (i < 0 || i > 127)
		std::cout << CYAN "char:	" GREEN "impossible" RESET << std::endl;
	else if (std::isprint(static_cast<char>(i)))
		std::cout << CYAN "char:	" RESET "'" GREEN << static_cast<char>(i) << RESET "'" << std::endl;
	else
		std::cout << CYAN "char:	" GREEN "Non displayable" RESET << std::endl;
}

void ScalarConverter::printCharFromFloat(float f) {
	if (f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max() || std::isnan(f) || std::isinf(f))
		std::cout << CYAN "char:	" GREEN "impossible" RESET << std::endl;
	else if (std::isprint(static_cast<char>(f)))
		std::cout << CYAN "char:	" RESET "'" GREEN << static_cast<char>(f) << RESET "'" << std::endl;
	else
		std::cout << CYAN "char:	" GREEN "Non displayable" RESET << std::endl;
}

void ScalarConverter::printCharFromDouble(double d) {
	if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max() || std::isnan(d) || std::isinf(d))
		std::cout << CYAN "char:	" GREEN "impossible" RESET << std::endl;
	else if (std::isprint(static_cast<char>(d)))
		std::cout << CYAN "char:	" RESET "'" GREEN << static_cast<char>(d) << RESET "'" << std::endl;
	else
		std::cout << CYAN "char:	" GREEN "Non displayable" RESET << std::endl;
}


void ScalarConverter::printIntFromFloat(float f) {
	if (f < static_cast<float>(std::numeric_limits<int>::min()) || f > static_cast<float>(std::numeric_limits<int>::max()) || std::isnan(f) || std::isinf(f))
		std::cout << MAGENTA "int:	" GREEN "impossible" << std::endl;
	else
		std::cout << MAGENTA "int:	" GREEN << static_cast<int>(f) << RESET << std::endl;
}

void ScalarConverter::printIntFromDouble(double d) {
	if (d < static_cast<double>(std::numeric_limits<int>::min()) || d > static_cast<double>(std::numeric_limits<int>::max()) || std::isnan(d) || std::isinf(d))
		std::cout << MAGENTA "int:	" GREEN "impossible" << std::endl;
	else
		std::cout << MAGENTA "int:	" GREEN << static_cast<int>(d) << RESET << std::endl;
}

void ScalarConverter::printFloatFromChar(char c) {
	std::cout << std::fixed << std::setprecision(1);
	std::cout << ORG "float:	" GREEN << static_cast<float>(c) << "f" RESET << std::endl;
}

void ScalarConverter::printDoubleFromChar(char c) {
	std::cout << std::fixed << std::setprecision(1);
	std::cout << BLUE "double:	" GREEN << static_cast<double>(c) << RESET << std::endl;
}

void ScalarConverter::printFloatFromInt(int i) {
	std::cout << std::fixed << std::setprecision(1);
		if (i < -std::numeric_limits<float>::max() || i > std::numeric_limits<float>::max()) {
			std::cout << ORG "float:	" GREEN "impossible" RESET << std::endl;
		} else 
			std::cout << ORG "float:	" GREEN << static_cast<float>(i) << "f" RESET << std::endl;
}

void ScalarConverter::printDoubleFromInt(int i) {
	std::cout << std::fixed << std::setprecision(1);
	std::cout << BLUE "double:	" GREEN << static_cast<double>(i) << RESET << std::endl;
}

void ScalarConverter::printFloatFromDouble(double d) {
	if (d < static_cast<double>(-std::numeric_limits<float>::min()) || d > static_cast<double>(std::numeric_limits<float>::max()))
		std::cout << ORG "float:	" GREEN "impossible" << std::endl;
	else
		std::cout << ORG "float:	" GREEN << static_cast<float>(d) << "f" RESET << std::endl;
}

