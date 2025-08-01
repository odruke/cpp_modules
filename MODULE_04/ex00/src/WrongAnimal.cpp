#include "WrongAnimal.hpp"

/* ============= Constructors and destructor ============ */
WrongAnimal::WrongAnimal(void) : Animal(){
	this->_type = "WrongAnimal";
	std::cout << YELLOW << "WrongAnimal" << GREEN << " constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& copy) : Animal(copy){
	std::cout << YELLOW << "WrongAnimal" << GREEN << " constructor by copy called" << RESET << std::endl;
}

WrongAnimal::~WrongAnimal(void){
	std::cout << YELLOW << "WrongAnimal" << RED << " destructor called" << RESET << std::endl;
}

/* ============== assignment operator ============= */
WrongAnimal& WrongAnimal::operator=(WrongAnimal const& copy){
	if (this != &copy)
		this->_type = copy._type;
	std::cout << YELLOW << "WrongAnimal" << CYAN << " assignment operator called" << RESET << std::endl;
	return *this;
}

/* ============== member functions ============= */
void	Animal::makeSound(void){
	std::cout << YELLOW << this->_type << RESET << ": groeurf!" << std::endl;
}


