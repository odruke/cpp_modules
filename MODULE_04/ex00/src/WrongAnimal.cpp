#include "WrongAnimal.hpp"

/* ============= Constructors and destructor ============ */
WrongAnimal::WrongAnimal(void) : _type("WrongAnimal"){
	std::cout << YELLOW << "\nWrongAnimal" << GREEN << " constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& copy) : _type(copy._type){
	std::cout << YELLOW << "\nWrongAnimal" << GREEN << " constructor by copy called" << RESET << std::endl;
}

WrongAnimal::~WrongAnimal(void){
	std::cout << YELLOW << "WrongAnimal" << RED << " destructor called\n" << RESET << std::endl;
}

/* ============== assignment operator ============= */
WrongAnimal& WrongAnimal::operator=(WrongAnimal const& copy){
	if (this != &copy)
		this->_type = copy._type;
	std::cout << YELLOW << "\nWrongAnimal" << CYAN << " assignment operator called" << RESET << std::endl;
	return *this;
}

/* ============== member functions ============= */
void	WrongAnimal::makeSound(void) const{
	std::cout << YELLOW << this->_type << RESET << ": Wrong blabla! " << std::endl;
}

/* ============== getters and setters ============= */

std::string	WrongAnimal::getType(void) const{
	return this->_type;
}

void	WrongAnimal::setType(std::string const& type){
	this->_type = type;
}
