/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:28:46 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/07 13:35:14 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhoneBook.hpp"

PhoneBook::PhoneBook(): _Index(0), _Counter(0) {}
PhoneBook::~PhoneBook(){}

std::string PhoneBook::trim_Display(std::string contact_info)
{
	if (contact_info.size() > 10)
		return (contact_info.substr(0, 9) + '.');
	return (contact_info); 
}

int PhoneBook::check_Contact_Index()
{
	int		input;
	bool	valid = false;
	do
	{
		std::cout << ORG "\nPlease Select Your Desired Contact Index: " RESET << std::flush;
		std::cin >> input;
		if (!std::cin.fail() && (input > 0 && input <= _Index))
			valid = true;
		else
		{
			std::cout << RED "This Index Number Doesn't Exist In The Phonebook!" RESET << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!valid);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return (input - 1);

}

void PhoneBook::get_Contact()
{
	int i = -1;

	if (_Counter == 0){
		std::cout << RED "Phonebook is empty!" RESET<< std::endl;
		return ; 
	}
	std::cout << " ___________________________________________________" << std::endl;
	std::cout << "| " << ORG "  INDEX   " RESET << " | " << ORG "FIRST_NAME" RESET << " | " << ORG "LAST__NAME" RESET << " | " << ORG "NICK__NAME" RESET << " |" << std::endl;
	std::cout << "|____________|____________|____________|____________|" << std::endl;
	while (++i < _Index)
	{
		std::cout << "| " << GREEN << std::setw(10) << i + 1 << RESET << " | " << std::flush;
		std::cout << GREEN <<  std::setw(10) << trim_Display(_contacts[i].getFirstName()) << RESET " | " << std::flush;
		std::cout << GREEN << std::setw(10) << trim_Display(_contacts[i].getLastName()) << RESET " | " << std::flush;
		std::cout << GREEN << std::setw(10) << trim_Display(_contacts[i].getNickName()) << RESET " |" << std::endl;
	}
	std::cout << "|____________|____________|____________|____________|" << std::endl;
		i = check_Contact_Index();
		std::cout << GREEN "-----The Information Of The Contact Number: '" << RED << i + 1 << GREEN "' Is As Fallow-----" RESET << std::endl;
		std::cout << ORG "First Name: " GREEN << _contacts[i].getFirstName() << RESET << std::endl; 
		std::cout << ORG "Last Name: " GREEN << _contacts[i].getLastName() << RESET << std::endl; 
		std::cout << ORG "Nick Name: " GREEN << _contacts[i].getNickName() << RESET << std::endl; 
		std::cout << ORG "Phone Number: " GREEN << _contacts[i].getPhoneNumber() << RESET << std::endl; 
		std::cout << ORG "Darkest Secret: " GREEN << _contacts[i].getSecret() << RESET << std::endl << std::endl;
}

void	PhoneBook::check_Contact_Info_Inputs(std::string *input, std::string prompt)
{
	bool		valid = false;

	while (!valid)
	{
		std::cout << ORG << prompt << RESET << std::flush;
		std::getline(std::cin, *input);
		if (std::cin.good() && !input->empty())
			valid = true;
		else
		{
			std::cout << RED "Wrong Entry!; Try Again." RESET << std::endl;
			std::cin.clear();
		}
	}
}
int PhoneBook::get_Index(int *index, int *counter)
{
	int i = 0;

	if (*counter >= MAX_INDEX){
		i = (*counter % MAX_INDEX);
		(*counter)++;
		return (i);
	}
	else
		i = *counter;
	*index = ++(*counter);
	// printf("i:%d index:%d CONTER:%d\n", i, *index, *counter);
	return (i);
}

void PhoneBook::set_Contact()
{
	std::string	firstname, lastname, nickname, phonenum, secret;

	this->check_Contact_Info_Inputs(&firstname, "Enter the Firstname: ");
	this->check_Contact_Info_Inputs(&lastname, "Enter the Lastname: ");
	this->check_Contact_Info_Inputs(&nickname, "Enter the Nickname: ");
	this->check_Contact_Info_Inputs(&phonenum, "Enter the Phonenumber: ");
	this->check_Contact_Info_Inputs(&secret, "Enter the Darkest_Secret: ");
	_contacts[get_Index(&_Index, &_Counter)] = Contact(firstname, lastname, nickname, phonenum, secret);
	std::cout << GREEN "-----New Contact Has Been Added!-----" RESET << std::endl << std::endl;
}
