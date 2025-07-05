#include "Zombie.hpp"

/*The number of zombies can be changed at compilation
 using make NBZOMBIES=n (n as the number desired)*/

int	main()
{
	std::cout << "the horde is coming!" << std::endl;

	Zombie* horde = zombieHorde(NBZOMBIES, "jose manuel");
	if (!horde)
		return EXIT_FAILURE;

	for (int i = 0; i < NBZOMBIES; i++)
		horde->announce();

	std::cout << "The horde is about to die!" << std::endl;
	delete[] horde;

	std::cout << "can't be the horde with no zombies!" << std::endl;
	horde = zombieHorde(0, "noOne");
	if (!horde)
		return EXIT_FAILURE;

	return EXIT_SUCCESS;
}
