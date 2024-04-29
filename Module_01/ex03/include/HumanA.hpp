/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 10:37:39 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/04/29 00:38:36 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA{
	private:
		std::string	_Name;
		Weapon&		_Weapon;

	public:
		HumanA(std::string name, Weapon& type);
		~HumanA();
		void	attack( void ) const;
};
#endif