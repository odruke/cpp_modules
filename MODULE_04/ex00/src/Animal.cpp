#include "Animal.hpp"

/* Constructors and destructor*/
Animal::Animal(void) : _type("def_animal")
{
	std::cout << WHITE << "Animal" << GREEN << " constructor called" << RESET << std::endl;
}

Animal::Animal(std::string const& type)
{
	this->_type = type;
	std::cout << WHITE << "Animal" << GREEN << " constructor by type called" << RESET << std::endl;
}

Animal::Animal(Animal const& copy)
{
	*this = copy;
	std::cout << WHITE << "Animal" << GREEN << " constructor by copy called" << RESET << std::endl;
}

Animal::Animal(std::string const& type)
{
	std::cout << WHITE << "Animal" << GREEN << " constructor called" << RESET << std::endl;
}

Animal::~Animal()
{
	std::cout << WHITE << "Animal" << RED << " destructor called" << RESET << std::endl;
}

/* assignment operator */
Animal Animal::operator=(Animal const& copy)
{
	this->_type = copy._type;
	std::cout << WHITE << "Animal" << CYAN << " assignment operator called" << RESET << std::endl;
	return *this;
}
