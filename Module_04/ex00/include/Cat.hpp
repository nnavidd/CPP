/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 01:39:03 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/20 10:40:52 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "../include/Animal.hpp"

class Cat : public Animal{
	public:
		Cat( void );
		Cat(Cat const &);
		Cat	& operator=(Cat const &);
		~Cat ( void );
		
		void makeSound( void ) const;
};
#endif