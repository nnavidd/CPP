#include "./Zombie.hpp"

int main (int ac, char **av)
{
    if (ac == 3)
    {
        Zombie  *New = newZombie(av[1]);
        New->Announce();
        randomChump(av[2]);
        delete New;
    }
    else
    {
        Zombie  *New = newZombie("Foo");
        New->Announce();
        randomChump("Joo");
        delete New;
    }
    return (0);
}