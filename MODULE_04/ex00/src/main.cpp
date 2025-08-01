#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main()
{
	// Animal animal;
	// Dog dog;
	// Cat cat;
	// std::cout << std::endl;

	// animal.makeSound();
	// std::cout << std::endl;
	// dog.makeSound();
	// std::cout << std::endl;
	// cat.makeSound();
	// std::cout << std::endl;

	// Cat	copyCat(cat);
	// copyCat.makeSound();

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << GREEN << "\nEnd of tests, calling destructors ->" << RESET << std::endl;

	delete meta;
	delete j;
	delete i;

}
