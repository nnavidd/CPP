#ifndef CONTACT_HPP
# define CONTACT_HPP

# define BLUE		"\033[38;5;4m"
# define GREEN		"\033[38;5;2m"  // For a bright green try 10 instead of 2
# define ORG		"\033[38;5;214m"
# define RED		"\033[38;5;196m"
# define RESET		"\033[0m"

# include <iostream>
# include <string>
# include <cstdio>
# include <limits>
# include <iomanip>
#include <stdio.h>


class Contact{
	public:
		Contact();
		~Contact();
		Contact(std::string firstname, std::string lastname, std::string nickname, std::string phonenum, std::string secret);
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string	getPhoneNumber() const;
		std::string	getSecret() const;

	private:
		std::string	_FirstName;
		std::string	_LastName;
		std::string	_NickName;
		std::string	_PhoneNumber;
		std::string	_Secret;
};

#endif