#include "Animal.hpp"

/* ========== Constructors and destructor ==============*/
Animal::Animal(void) : _type("def_animal"){
	std::cout << WHITE << "\nAnimal" << GREEN << " constructor called" << RESET << std::endl;
}

Animal::Animal(Animal const& copy) : _type(copy._type){
	std::cout << WHITE << "\nAnimal" << GREEN << " constructor by copy called" << RESET << std::endl;
}

Animal::~Animal(){
	std::cout << WHITE << "Animal" << RED << " destructor called\n" << RESET << std::endl;
}

/* ============== assignment operator ============= */
Animal& Animal::operator=(Animal const& copy){
	if (this != &copy)
		this->_type = copy._type;
	std::cout << WHITE << "\nAnimal" << CYAN << " assignment operator called" << RESET << std::endl;
	return *this;
}

/* ============== member functions ============= */
void	Animal::makeSound(void) const{
	std::cout << WHITE << this->_type << RESET << ": blablabla" << std::endl;
}

/* ============== getters and setters ============= */

std::string	Animal::getType(void) const{
	return this->_type;
}

void	Animal::setType(std::string const& type){
	this->_type = type;
}
