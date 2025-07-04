#include "Zombie.hpp"

int	main()
{
	std::cout << "calling newZombie" << std::endl;
	Zombie* zombie = newZombie("heapy");
	zombie->announce();

	std::cout << "calling randomChump" << std::endl;
	randomChump("stacky");

	std::cout << "killing heapy" << std::endl;
	delete zombie;
}
