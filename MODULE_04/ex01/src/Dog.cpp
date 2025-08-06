#include "Dog.hpp"

/* ============= Constructors and destructor ============ */
Dog::Dog(void) : Animal(){
	this->_type = "Dog";
	std::cout << BLUE << "Dog" << GREEN << " constructor called" << RESET << std::endl;
}

Dog::Dog(Dog const& copy) : Animal(copy){
	std::cout << BLUE << "Dog" << GREEN << " constructor by copy called" << RESET << std::endl;
}

Dog::~Dog(void){
	std::cout << BLUE << "Dog" << RED << " destructor called" << RESET << std::endl;
}

/* ============= assignment operator ===================*/
Dog&	Dog::operator=(Dog const& copy){
	if (this != &copy)
		Animal::operator=(copy);
	std::cout << BLUE << "Dog" << CYAN << " assignment operator called" << RESET << std::endl;
	return *this;
}

/* ============== member functions ============= */
void	Dog::makeSound(void) const{
	std::cout << BLUE << this->_type << RESET << ": Woof!, Woof!" << std::endl;
}
