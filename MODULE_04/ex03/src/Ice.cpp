#include "Ice.hpp"

/* ========== Constructors and destructor ==============*/
Ice::Ice(void) : AMateria("ice"){
	std::cout << CYAN << "Ice" << GREEN << " default constructor called" << RESET << std::endl;
}

Ice::Ice(Ice const& copy) : AMateria(copy){
	std::cout << CYAN << "Ice" << GREEN << " constructor by type called" << RESET << std::endl;
}

Ice::~Ice(void){
	std::cout << CYAN << "Ice" << RED << " destructor called" << RESET << std::endl;
}

/* ============== assignment operator ============= */
Ice&	Ice::operator=(Ice const& other){
	if (this != &other)
		this->_type = other._type;
	std::cout << CYAN << "Ice" << BLUE << " assignment operator called" << RESET << std::endl;
	return *this;
}

/* ============== member functions ============= */
AMateria* Ice::clone(void) const{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

