/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:36:14 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/15 23:14:33 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include <fstream>
# include "./AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;

	public:

		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm(void);
		
		void execute(const Bureaucrat &executor) const;

		class FileOpenFailed : public std::exception{
			virtual const char * what() const throw(){
				return ("This file couldn't open!");
			}
		};
};


#endif