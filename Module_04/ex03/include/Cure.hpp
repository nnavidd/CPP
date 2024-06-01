/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 23:40:32 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/28 01:06:24 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cure_HPP
# define Cure_HPP

# include <iostream>
# include <string>
# include "./AMateria.hpp"

class Cure: public AMateria{
	private:

	public:
		Cure( void );
		Cure(Cure const &);
		Cure & operator=(Cure const &);
		~Cure( void );

		AMateria *clone(void) const;
		void use(ICharacter &target);
};

#endif