#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <cstdlib>
#include <ctime>
#include <cstdio>
#define MAX_ANIMALS 10

int randomPos(int max)
{
	static bool seeded = false;

	if (!seeded) {
		srand(time(NULL));
		seeded = true;
	}
	return rand() % (max + 1);
}

int	main()
{
	if (DEFAULT){

		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;

		return 0;
	}
/*============ Creating animals =============*/
	std::cout << CYAN << "--- Creating animals ---" << RESET << std::endl;
	Animal *animal[MAX_ANIMALS];

	int i = 0;
	while (i < (MAX_ANIMALS / 2)){
		animal[i++] = new Dog();
	}
	while (i < MAX_ANIMALS){
		animal[i++] = new Cat();
	}
	std::cout << std::endl;

/*============ Making sounds =============*/
	std::cout << CYAN << "--- Making sounds ---" << RESET << std::endl;
	i = 0;
	while(i < MAX_ANIMALS){
		animal[i++]->makeSound();
	}
	std::cout << std::endl;

/*============ Listening thougths =============*/
	std::cout << CYAN << "--- listening thougths ---" << RESET << std::endl;
	i = -1;
	while(++i < MAX_ANIMALS){
		int pos = randomPos(MAX_IDEAS - 1);
		std::cout
			<< animal[i]->getType() << " thinks in "
			<< animal[i]->getBrain().getIdea(pos)
			<< std::endl;
	}
	std::cout << std::endl;

/*============ Schrodinger's cat =============*/
	std::cout << CYAN << "--- schrodinger's cat ---" << RESET << std::endl;
	{
	Cat cat;
	{
		Cat copycat = cat;
	}
	std::cout
			<< cat.getType() << " is alive and thinks in "
			<< cat.getBrain().getIdea(0) << std::endl;
	}

/*============ End Tests, calling destructors =============*/
	std::cout << CYAN << "--- End Tests, calling destructors ---" << RESET << std::endl << std::endl;
	std::cout << std::endl;
	i = 0;
	while(i < MAX_ANIMALS){
		delete animal[i++];
	}
	return 0;
}
