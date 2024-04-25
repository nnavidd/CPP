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

Zombie* newZombie(std::string name);
void    randomChump( std::string name );

#endif
