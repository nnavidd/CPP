/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 01:39:03 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/24 01:09:27 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "../include/Animal.hpp"
# include "../include/Brain.hpp"

class Dog : public Animal{
	private:
		Brain	*_idea;
	public:
		Dog( void );
		Dog(Dog const &);
		Dog	& operator=(Dog const &);
		~Dog ( void );
		
		void makeSound( void ) const;
		bool setData(int index, std::string const idea);
		void getData( int index ) const;
};
#endif