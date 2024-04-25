#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "./Contact.hpp"

# define MAX_INDEX 8

class PhoneBook{
	public:
		PhoneBook();
		~PhoneBook();
		void		set_Contact();
		void		get_Contact();
		void		check_Contact_Info_Inputs(std::string *input, std::string prompt);
		int			check_Contact_Index();
		int			get_Index(int *index, int *counter);
		std::string	trim_Display(std::string contact_info);
	private:
		Contact _contacts[MAX_INDEX];
		int		_Index;
		int		_Counter;
};

#endif