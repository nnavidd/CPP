/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 23:56:20 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/15 10:06:36 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "./ClapTrap.hpp"

// Same things for the attributes, but with different values this time:
// • Name, which is passed as parameter to a constructor
// • Hit points (100), represent the health of the ClapTrap
// • Energy points (100)
// • Attack damage (30)
// FragTrap has a special capacity too:
// void highFivesGuys(void);
// This member function displays a positive high fives request on the standard output.
// Again, add more tests to your program.

class FragTrap: public ClapTrap{
	public:
		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( FragTrap const &);
		FragTrap & operator=( FragTrap const &);
		~FragTrap( void );

		void	highFivesGuys( void );

};
#endif