/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 00:02:47 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/16 09:41:06 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include <exception>
# include <fstream>
# include "./AForm.hpp"

class Intern {
	private:

	public:
		Intern( void );
		Intern(Intern const &);
		Intern & operator=(Intern const &);
		~Intern( void );

		AForm	 *makeForm(std::string FormName, std::string target);

		class Exception : public std::exception{
			virtual const char* what() const throw(){
				return ( ORG "This type of Form doesn't exist!!!" RESET);
			}
		};
};
#endif