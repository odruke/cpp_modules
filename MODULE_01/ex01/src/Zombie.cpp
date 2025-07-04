#include "Zombie.hpp"

Zombie::Zombie()
{
	return;
}

Zombie::Zombie(std::string name)
{
	Zombie::name = name;
	return;
}

Zombie::~Zombie(void)
{
	std::cout << "The zombie " << Zombie::name
	<< " was shot in the head!" << std::endl;
	return;
}

void Zombie::announce( void )
{
	std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

