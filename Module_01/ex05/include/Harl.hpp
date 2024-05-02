/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:44:12 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/01 01:50:37 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HARL_HPP
# define HARL_HPP

# define BLUE		"\033[38;5;4m"
# define GREEN		"\033[38;5;2m"
# define ORG		"\033[38;5;214m"
# define RED		"\033[38;5;196m"
# define RESET		"\033[0m"

# include <string>
# include <iostream>
# include <map>
# include <cstdio>


class Harl {
	private:
		typedef void (Harl::*Level)(void);
		
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

		std::map<std::string, Level> _HarlAction;

	public:
		Harl();
		~Harl();
		void complian(std::string);
};
#endif