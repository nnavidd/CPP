/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:28:53 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/07 15:14:50 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

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
# include <stdio.h>
# include <sstream>

# include "./Contact.hpp"

# define MAX_INDEX 8

class PhoneBook{
	public:
		PhoneBook();
		~PhoneBook();
		void		set_Contact();
		void		get_Contact();

	private:
		std::string	trim_Display(std::string contact_info);
		void		check_Contact_Info_Inputs(std::string *input, std::string prompt);
		int			check_Contact_Index();
		int			get_Index(int *index, int *counter);
		Contact 	_contacts[MAX_INDEX];
		int			_Index;
		int			_Counter;
};

#endif