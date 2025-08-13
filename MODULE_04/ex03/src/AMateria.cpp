#include "AMateria.hpp"

/* ========== Constructors and destructor ==============*/
AMateria::AMateria(void){
	std::cout << WHITE << "\nAMateria" << GREEN << " default constructor called" << RESET << std::endl;
}

AMateria::AMateria(std::string const& type) : _type(type){
	std::cout << WHITE << "\nAMateria" << GREEN << " constructor by type called" << RESET << std::endl;
}

AMateria::AMateria(AMateria const& copy) : _type(copy._type){
	std::cout << WHITE << "\nAMateria" << GREEN << " constructor by copy called" << RESET << std::endl;
}

AMateria::~AMateria(){
	std::cout << WHITE << "AMateria" << RED << " destructor called\n" << RESET << std::endl;
}

/* ============== assignment operator ============= */
AMateria&	AMateria::operator=(AMateria const& other){
	if (this != &other)
		this->_type = other._type;
	std::cout << WHITE << "\nAMateria" << BLUE << " assignment operator called" << RESET << std::endl;
		return *this;
}

/* ============== getters and setters ============= */
std::string const&	AMateria::getType(void) const {
	return this->_type;
}


void	AMateria::use(ICharacter& target){
	(void)target;
	//void
}
