#include "PhoneBook.hpp"

int	main()
{
	Phonebook	phonebook;
	std::string	command;

	do{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::cin >> command;

		if (command == "ADD")
			phonebook.addcontact();
		else if (command == "SEARCH")
			phonebook.searchcontact();
		else if (command == "EXIT")
		{
			std::cout << "Goodbye!" << std::endl;
			break ;
		}
		else
			std::cout << "Invalid command. Write correct commamd." << std::endl;
	} while (true);

	return (0);
}