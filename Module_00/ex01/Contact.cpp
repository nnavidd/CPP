#include "./Contact.hpp"
// #include "./PhoneBook.hpp"

Contact::Contact():_FirstName(""), _LastName(""), _NickName(""), _PhoneNumber(""), _Secret("") {}
Contact::~Contact() {}

Contact::Contact(std::string firstname, std::string lastname, std::string nickname, std::string phonenum, std::string secret)
	: _FirstName(firstname), _LastName(lastname), _NickName(nickname), _PhoneNumber(phonenum), _Secret(secret) {}

std::string	Contact::getFirstName() const {return (_FirstName);};
std::string	Contact::getLastName() const {return (_LastName);};
std::string	Contact::getNickName() const {return (_NickName);};
std::string	Contact::getPhoneNumber() const {return (_PhoneNumber);};
std::string	Contact::getSecret() const {return (_Secret);};