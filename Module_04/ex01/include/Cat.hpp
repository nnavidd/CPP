/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 01:39:03 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/10 18:48:21 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "../include/Animal.hpp"
# include "../include/Brain.hpp"

class Cat : public Animal{
	private:
		Brain	*_brain;
		
	public:
		Cat( void );
		Cat(Cat const &);
		Cat	& operator=(Cat const &);
		~Cat ( void );
		
		void makeSound( void ) const;
		bool setData(int index, std::string const idea);
		void getData( int index ) const;
};
#endif