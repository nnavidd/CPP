/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 00:44:58 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/10 19:29:57 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "./AMateria.hpp"
# include "./IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria *_memory[4];

	public:
		MateriaSource( void );
		MateriaSource(MateriaSource const &);
		MateriaSource & operator=(MateriaSource const &);
		~MateriaSource( void );

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);

};

#endif