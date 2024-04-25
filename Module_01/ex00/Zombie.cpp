#include "./Zombie.hpp"


Zombie::Zombie(std::string name): _Name(name){std::cout << this->_Name << " Is Created!" << std::endl;}
Zombie::~Zombie(){std::cout  << this->_Name << " Is Destroyed!" << std::endl;}
void    Zombie::Announce(void){std::cout << this->_Name << ": BraiiiiiiinnnzzzZ..." << std::endl;}
