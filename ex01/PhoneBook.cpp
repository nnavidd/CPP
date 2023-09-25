#include "PhoneBook.hpp"

Phonebook::Phonebook(void){
	contacts[8];
	oldestcontactindex = 0;
}

void	Phonebook::addcontact()
{
    Contact newContact;

    // Prompt the user for contact information and use setter methods
    std::string fName, lName, nick, phone, secret;
	
	std::cout << "Please Enter Your First Name: " << std::endl;
	std::cin >> fName;
	newContact.setfild("firstname", fName);
	
	std::cout << "Please Enter Your Last Name: " << std::endl;
	std::cin >> lName;
	newContact.setfild("lastname", lName);
	
	std::cout << "Please Enter Your Nickname: " << std::endl;
	std::cin >> nick;
	newContact.setfild("nickname", nick);
	
	std::cout << "Please Enter Your Phone Number: " << std::endl;
	std::cin >> phone;
	newContact.setfild("phonenumber", phone);
	
	std::cout << "Please Enter Your Darkest Secret: " << std::endl;
	std::cin >> secret;
	newContact.setfild("darkestsecret", secret);
	
    // Get input for each field and set it using newContact.setXXX methods

    // Add the new contact to the phonebook array, replacing the oldest if necessary
    contacts[oldestcontactindex] = newContact;
    oldestcontactindex = (oldestcontactindex + 1) % 8; // Circular buffer
	// if (oldestcontactindex == 8)
	// 	oldestcontactindex = 0;
	// std::cin >> Contact::setfild(firstname, this->contacts[oldestcontactindex].Firstname);
	// oldestcontactindex++;	
}

void Phonebook::searchcontact()
{
    // Display contacts as specified (four columns, right-aligned, truncated if needed)
    int index = 0;

    // Print header for the contact list
    std::cout << std::setw(10) << "Index" << std::setw(10) << "First Name" << std::setw(10) << "Last Name" << std::setw(10) << "Nickname" << std::endl;
    // Loop through the contacts and print them
    for (const Contact& contact : contacts) {
        std::cout << std::setw(10) << index << std::setw(10) << contact.getfild("firsname") << std::setw(10) << contact.getfild("lastname") << std::setw(10) << contact.getfild("nickname") << std::endl;
        index++;
    }

    // Prompt the user for an index
    int userInputIndex;
    std::cout << "Enter the index of the contact you want to display: ";
    std::cin >> userInputIndex;

    // Check if the user input is valid
    if (userInputIndex >= 0 && userInputIndex < contacts.size()) {
        // Display the contact using the displayContact method
        contacts[userInputIndex].displaycotact();
    } else {
        std::cout << "Invalid index. Please enter a valid index." << std::endl;
    }
}
