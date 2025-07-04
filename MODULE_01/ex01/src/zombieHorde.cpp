#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0){
		std::cout << "N must be a number over 0!" << std::endl;
		return NULL;
	}
	Zombie* horde = new Zombie[N];
	if (!horde){
		std::cout << "allocation failed" << std::endl;
		return NULL;
	}

	for (int i = 0; i < N; i++)
		horde[i].setName(name);

	return horde;
}
