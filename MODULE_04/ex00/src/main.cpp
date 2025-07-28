#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main()
{
	std::cout << CYAN << "=== Animal Polymorphism Demo ===" << RESET << std::endl;

	Animal animal;
	Dog dog;
	Cat cat;

	std::cout << GREEN << "Demo completed!" << RESET << std::endl;
	return 0;
}
