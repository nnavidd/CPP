#include <iostream>

class Contact {
private:
	std::string	Firstname;
	std::string	Lastname;
	std::string	Nickname;
	std::string	Phonenumber;
	std::string	Darkestsecret;
public:
				Contact();
	void		displaycotact();
	void		setfild(const std::string &fildname, const	std::string &value);
	std::string	getfild(const std::string &fildname) const;
};
