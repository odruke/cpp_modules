
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#ifndef NBZOMBIES
# define NBZOMBIES 5
#endif
#include <iostream>
#include <cstdlib>

class Zombie
{
private:
	std::string	name;
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void announce( void );
	void setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif
