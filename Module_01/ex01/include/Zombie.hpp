/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 00:25:53 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/04/26 18:30:16 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie{
	public:
		Zombie();
		~Zombie();
		void    Announce(void);
		void    setName( std::string name );

	private:
	std::string _Name;
};

Zombie*  zombieHorde(int N, std::string name);

#endif
