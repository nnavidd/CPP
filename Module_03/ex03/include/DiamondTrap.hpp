/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 23:49:27 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/17 23:06:27 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>
# include "./ScavTrap.hpp"
# include "./FragTrap.hpp"

/*In this exercise, you will create a monster: a ClapTrap that’s half FragTrap, half
ScavTrap. It will be named DiamondTrap, and it will inherit from both the FragTrap
AND the ScavTrap. This is so risky!
The DiamondTrap class will have a name private attribute. Give to this attribute
exactly the same variable’s name (not talking about the robot’s name here) than the one
in the ClapTrap base class.
To be more clear, here are two examples.
If ClapTrap’s variable is name, give the name name to the one of the DiamondTrap.
If ClapTrap’s variable is _name, give the name _name to the one of the DiamondTrap.
Its attributes and member functions will be picked from either one of its parent classes:
• Name, which is passed as parameter to a constructor
• ClapTrap::name (parameter of the constructor + "_clap_name" suffix)
• Hit points (FragTrap)
• Energy points (ScavTrap)
• Attack damage (FragTrap)
• attack() (Scavtrap)
In addition to the special functions of both its parent classes, DiamondTrap will have
its own special capacity:
void whoAmI();
This member function will display both its name and its ClapTrap name.
Of course, the ClapTrap subobject of the DiamondTrap will be created once, and only
once. Yes, there’s a trick.
Again, add more tests to your program.*/

class DiamondTrap: public ScavTrap, public FragTrap{
// class DiamondTrap: public ClapTrap{
	private:
		std::string	_name;

	public:
		DiamondTrap( void );
		DiamondTrap( std::string name );
		DiamondTrap( DiamondTrap const & );
		DiamondTrap & operator=( DiamondTrap const & );
		~DiamondTrap( void );
		void	whoAmI( void );
		void	attack(std::string const & target);

};
#endif