#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class Phonebook{
private:
	Contact	contacts[8];
	int		oldestcontactindex;
public:
	Phonebook();
	~Phonebook();
	void	addcontact();
	void	searchcontact();
};

