/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 23:40:32 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/10 19:35:22 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cure_HPP
# define Cure_HPP

# include <iostream>
# include <string>
# include "./AMateria.hpp"

class Cure: public AMateria {
	private:
	public:
		Cure( void );
		Cure( Cure const & );
		Cure & operator=( Cure const & );
		~Cure( void );

		AMateria *clone( void ) const;
		void use( ICharacter & target );
};

#endif