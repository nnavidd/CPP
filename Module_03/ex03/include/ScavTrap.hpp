/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:15:20 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/10 12:27:56 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "./ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
	public:
	ScavTrap( void );
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const & other);
	ScavTrap & operator=(ScavTrap const &);
	~ScavTrap( void );

	void	guardGate( void );
	void	attack(std::string const & target);

};

# endif