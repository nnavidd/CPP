/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:01:24 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/14 21:28:59 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>
# include <cmath>

# define BLUE	"\033[38;5;4m"
# define GREEN	"\033[38;5;2m"
# define ORG	"\033[38;5;214m"
# define RED	"\033[38;5;196m"
# define RESET	"\033[0m"


class ClapTrap{
	protected:
		std::string		_name;
		unsigned int	_hit_point;
		unsigned int	_energy_point;
		unsigned int	_attack_damage;
	public:
		ClapTrap( void );
		ClapTrap(std::string const name);
		ClapTrap(ClapTrap const &);
		ClapTrap & operator=(ClapTrap const &);
		~ClapTrap( void );

		void	attack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	report( void ) const;
};

#endif