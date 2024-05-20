/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 01:39:03 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/20 10:40:49 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "../include/Animal.hpp"

class Dog : public Animal{
	public:
		Dog( void );
		Dog(Dog const &);
		Dog	& operator=(Dog const &);
		~Dog ( void );
		
		void makeSound( void ) const;
	
};
#endif