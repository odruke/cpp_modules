#include "Cure.hpp"

/* ========== Constructors and destructor ==============*/
Cure::Cure(void) : AMateria("cure"){
	std::cout << YELLOW << "cure" << GREEN << " default constructor called" << RESET << std::endl;
}

Cure::Cure(Cure const& copy) : AMateria(copy){
	std::cout << YELLOW << "cure" << GREEN << " constructor by type called" << RESET << std::endl;
}

Cure::~Cure(void){
	std::cout << YELLOW << "cure" << RED << " destructor called" << RESET << std::endl;
}

/* ============== assignment operator ============= */
Cure&	Cure::operator=(Cure const& other){
	if (this != &other)
		this->_type = other._type;
	std::cout << YELLOW << "cure" << BLUE << " assignment operator called" << RESET << std::endl;
	return *this;
}

/* ============== member functions ============= */
AMateria* Cure::clone(void) const{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
