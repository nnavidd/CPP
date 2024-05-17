/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:15:20 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/17 22:13:18 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "./ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
	public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const & other);
	ScavTrap & operator=(ScavTrap const &);
	~ScavTrap();

	void	guardGate();
	void	attack(std::string const & target);

};

# endif