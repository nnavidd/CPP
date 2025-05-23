/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:30:17 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/07 17:11:46 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie{
    public:
        Zombie(std::string name);
        ~Zombie();
        void    Announce(void);

    private:
    std::string _Name;
};

Zombie* newZombie( std::string name );
void    randomChump( std::string name );

#endif
