#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	if (DEFAULT){
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
		return 0;
	}
	/*============Test 1: Basic object creation and makeSound() =============*/
	std::cout << CYAN << "--- Test 1: Basic Object Creation ---" << RESET << std::endl;
	Animal animal;
	Dog dog;
	Cat cat;
	WrongAnimal wrongAnimal;
	WrongCat wrongCat;
	std::cout << std::endl;
	std::cout << std::endl;

	animal.makeSound();
	dog.makeSound();
	cat.makeSound();
	wrongAnimal.makeSound();
	wrongCat.makeSound();
	std::cout << CYAN << "--- End Test 1 ---" << RESET << std::endl << std::endl;
	std::cout << std::endl;


	/*============	Test 2: Copy Constructor =============*/
	std::cout << CYAN << "--- Test 2: Copy Constructors ---" << RESET << std::endl;
	Animal copyAnimal(animal);
	Dog copyDog(dog);
	Cat copyCat(cat);
	WrongAnimal copyWrongAnimal(wrongAnimal);
	WrongCat copyWrongCat(wrongCat);
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "Original sounds:" << std::endl;
	animal.makeSound();
	dog.makeSound();
	cat.makeSound();
	wrongAnimal.makeSound();
	wrongCat.makeSound();

	std::cout << "\nCopy sounds:" << std::endl;
	copyAnimal.makeSound();
	copyDog.makeSound();
	copyCat.makeSound();
	copyWrongAnimal.makeSound();
	copyWrongCat.makeSound();
	std::cout << CYAN << "--- End Test 2 ---" << RESET << std::endl << std::endl;
	std::cout << std::endl;


	/*============	Test 3: Assignment Operator =============*/
	std::cout << CYAN << "--- Test 3: Assignment Operators ---" << RESET << std::endl;
	Animal animal2;
	Dog dog2;
	Cat cat2;
	WrongAnimal wrongAnimal2;
	WrongCat wrongCat2;
	std::cout << std::endl;
	std::cout << std::endl;


	animal2 = animal;
	dog2 = dog;
	cat2 = cat;
	wrongAnimal2 = wrongAnimal;
	wrongCat2 = wrongCat;
	std::cout << std::endl;

	std::cout << "After assignment - sounds:" << std::endl;
	animal2.makeSound();
	dog2.makeSound();
	cat2.makeSound();
	wrongAnimal2.makeSound();
	wrongCat2.makeSound();
	std::cout << CYAN << "--- End Test 3 ---" << RESET << std::endl << std::endl;
	std::cout << std::endl;


	/*============	Test 4: Polymorphism with dynamic allocation =============*/
	std::cout << CYAN << "--- Test 4: Polymorphism (Dynamic Allocation) ---" << RESET << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* wrongcat = new WrongCat();
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "Types: " << std::endl;
	std::cout << "meta type: " << meta->getType() << std::endl;
	std::cout << "j type: " << j->getType() << std::endl;
	std::cout << "i type: " << i->getType() << std::endl;
	std::cout << "wrong type: " << wrong->getType() << std::endl;
	std::cout << "wrong cat type: " << wrongcat->getType() << std::endl;
	std::cout << std::endl;

	std::cout << "Polymorphic sounds:" << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	wrong->makeSound();
	wrongcat->makeSound();
	std::cout << CYAN << "--- End Test 4 ---" << RESET << std::endl << std::endl;
	std::cout << std::endl;


	/*============	Test 5: Array of Animal pointers =============*/
	std::cout << CYAN << "--- Test 5: Array of Animals ---" << RESET << std::endl;
	const Animal* animals[3];
	animals[0] = new Animal();
	animals[1] = new Dog();
	animals[2] = new Cat();
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "Array sounds:" << std::endl;
	for (int idx = 0; idx < 3; idx++)
	{
		std::cout << "Animal[" << idx << "] (" << animals[idx]->getType() << "): ";
		animals[idx]->makeSound();
	}
	std::cout << CYAN << "--- End Test 5 ---" << RESET << std::endl << std::endl;
	std::cout << std::endl;


	/*============	Test 6: Self-assignment test =============*/
	std::cout << CYAN << "--- Test 6: Self-Assignment Test ---" << RESET << std::endl;
	animal = animal;
	cat = cat;
	dog = dog;
	wrongAnimal = wrongAnimal;
	wrongCat = wrongCat;
	std::cout << std::endl;
	std::cout << std::endl;

	animal.makeSound();
	cat.makeSound();
	dog.makeSound();
	wrongAnimal.makeSound();
	wrongCat.makeSound();
	std::cout << CYAN << "--- End Test 6 ---" << RESET << std::endl << std::endl;
	std::cout << std::endl;


	// Clean up Test 4
	std::cout << GREEN << "--- free allocated memory ---" << RESET << std::endl;
	delete meta;
	delete j;
	delete i;
	delete wrong;
	delete wrongcat;

	// Clean up Test 5
	std::cout << GREEN << "--- free allocated memory on array ---" << RESET << std::endl;
	for (int idx = 0; idx < 3; idx++)
		delete animals[idx];

	std::cout << GREEN << "--- End of tests, calling destructors ---" << RESET << std::endl;
	return 0;
}
