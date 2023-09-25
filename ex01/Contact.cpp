#include "Contact.hpp"

Contact::Contact(){
	Firstname = "";
	Lastname = "";
	Nickname = "";
	Phonenumber = "";
	Darkestsecret = "";
}

void	Contact::setfild(const std::string &fildname, const std::string& value)
{
	if (fildname == "firstname")
		Firstname = value;
	else if (fildname == "lastname")
		Lastname = value;
	else if (fildname == "phonenumber")
		Phonenumber = value;
	else if (fildname == "darkestsecret")
		Darkestsecret = value;
	else if (fildname == "nickname")
		Nickname = value;
}

std::string	Contact::getfild(const std::string &fildname) const
{
	if (fildname == "firstname")
		return(Firstname);
	else if (fildname == "lastname")
		return(Lastname);
	else if (fildname == "phonenumber")
		return(Phonenumber);
	else if (fildname == "darkestsecret")
		return(Darkestsecret);
	return (NULL);
}