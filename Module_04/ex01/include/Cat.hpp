/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 01:39:03 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/23 16:32:32 by nnabaeei         ###   ########.fr       */
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
		Brain	*_idea;
	public:
		Cat( void );
		Cat(Cat const &);
		Cat	& operator=(Cat const &);
		~Cat ( void );
		
		void makeSound( void ) const;
		// void setData(std::string const idea);
		// void getData( void ) const;
};
#endif