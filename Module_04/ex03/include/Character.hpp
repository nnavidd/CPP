/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 00:41:13 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/01 10:16:14 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
#include "../include/AMateria.hpp"

class Character : public ICharacter {

	private:
		std::string	_name;
		AMateria	*_inventory[4];

		
		void clearInventory();
		void copyInventory(const Character& other);

	public:
		Character(void);
		Character(std::string const name);
		Character(Character  const &);
		Character &operator=(Character const &);
		~Character(void);

		const std::string &getName(void) const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};

#endif