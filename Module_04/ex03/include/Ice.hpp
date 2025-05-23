/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 23:37:05 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/10 19:30:19 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include "./AMateria.hpp"

class Ice: public AMateria {
	private:
	public:
		Ice( void );
		Ice(Ice const &);
		Ice & operator=(Ice const &);
		~Ice( void );

		AMateria *clone(void) const;
		void use(ICharacter &target);
};

#endif