#include "WrongCat.hpp"

/* ============= Constructors and destructor ============ */
WrongCat::WrongCat(void) : WrongAnimal(){
	this->_type = ("wrongCat");
	std::cout << ORANGE << "WrongCat" << GREEN << " constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(WrongCat const& copy) : WrongAnimal(copy){
	std::cout << ORANGE << "WrongCat" << GREEN << " constructor by copy called" << RESET << std::endl;
}

WrongCat::~WrongCat(void){
	std::cout << ORANGE << "WrongCat" << RED << " destructor called" << RESET << std::endl;
}

/* ============== assignment operator ============= */
WrongCat& WrongCat::operator=(WrongCat const& copy){
	if (this != &copy)
		this->_type = copy._type;
	std::cout << ORANGE << "WrongCat" << CYAN << " assignment operator called" << RESET << std::endl;
	return *this;
}

/* ============== member functions ============= */
void	WrongCat::makeSound(void) const{
	std::cout << ORANGE << this->_type << RESET << ": Wrong mew!" << std::endl;
}

