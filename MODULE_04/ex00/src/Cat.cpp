#include "Cat.hpp"

/* ================ Constructors and destructor ============== */
Cat::Cat(void) : Animal()
{
	this->_type = "Cat";
	std::cout << MAGENTA << "Cat" << GREEN << " constructor called" << RESET << std::endl;
}

Cat::Cat(Cat const& copy) : Animal(copy)
{
	std::cout << MAGENTA << "Cat" << GREEN << " copy constructor called" << RESET << std::endl;
}
Cat::~Cat(void)
{
	std::cout << MAGENTA << "Cat" << RED << " destructor called" << RESET << std::endl;
}

/* =================== assignment operator ================ */
Cat&	Cat::operator=(Cat const& copy)
{
	if (this != &copy)
		 Animal::operator=(copy);
std::cout << MAGENTA << "Cat" << CYAN << " assignment operator called" << RESET << std::endl;
	return *this;
}

/* ============== member functions ============= */
void	Cat::makeSound(void){
	std::cout << MAGENTA << this->_type << RESET << ": Mew! Mew!" << std::endl;
}
