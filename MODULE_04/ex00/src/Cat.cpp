#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << MAGENTA << "Cat" << GREEN << " constructor called" << RESET << std::endl;
}


Cat::~Cat()
{
	std::cout << MAGENTA << "Cat" << RED << " destructor called" << RESET << std::endl;
}
