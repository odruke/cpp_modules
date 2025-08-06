#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	if (DEFAULT){

		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;

		return 0;
	}
	/*============Test 1: subject mandate =============*/
	std::cout << CYAN << "--- Test 1: Basic Object Creation ---" << RESET << std::endl;
	Animal animal;
	Dog dog;
	Cat cat;
	std::cout << std::endl;

	std::cout << CYAN << "--- End Test 1 ---" << RESET << std::endl << std::endl;
	std::cout << std::endl;

	return 0;
}
