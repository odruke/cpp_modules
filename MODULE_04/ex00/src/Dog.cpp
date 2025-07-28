#include "Dog.hpp"

Dog::Dog()
{
	std::cout << BLUE << "Dog" << GREEN << " constructor called" << RESET << std::endl;
}

Dog::~Dog()
{
	std::cout << BLUE << "Dog" << RED << " destructor called" << RESET << std::endl;
}
