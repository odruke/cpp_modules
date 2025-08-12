#include "Cat.hpp"

/* ================ Constructors and destructor ============== */
Cat::Cat(void) : Animal(), _brain(new Brain()) {
	if (!this->_brain){
			std::cout << "brain allocation failed at: " << __FILE__ << ", " << __LINE__ << std::endl;
			exit(1);
	}
	for (int i = 0; i < MAX_IDEAS; i++){
		std::stringstream ss;
		ss << "cat thought n" << i;
		_brain->setIdea(ss.str(), i);
	}
	this->_type = "Cat";
	std::cout << MAGENTA << "Cat" << GREEN << " constructor called" << RESET << std::endl;
}

Cat::Cat(Cat const& copy) : Animal(copy), _brain(new Brain()){
	if (!this->_brain){
			std::cout << "brain allocation failed at: " << __FILE__ << ", " << __LINE__ << std::endl;
			exit(1);
	}
	for (int i = 0; i < MAX_IDEAS; i++){
		_brain->setIdea(copy._brain->getIdea(i), i);
	}
	std::cout << MAGENTA << "Cat" << GREEN << " copy constructor called" << RESET << std::endl;
}

Cat::~Cat(void){
	delete _brain;
	std::cout << MAGENTA << "Cat" << RED << " destructor called" << RESET << std::endl;
}

/* =================== assignment operator ================ */
Cat&	Cat::operator=(Cat const& copy){
	if (this != &copy){
		Animal::operator=(copy);
		delete this->_brain;
		this->_brain = new Brain();
		for (int i = 0; i < MAX_IDEAS; i++){
		_brain->setIdea(copy._brain->getIdea(i), i);
		}
	}
	std::cout << MAGENTA << "Cat" << CYAN << " assignment operator called" << RESET << std::endl;
	return *this;
}

/* ============== member functions ============= */
void	Cat::makeSound(void) const{
	std::cout << MAGENTA << this->_type << RESET << ": Mew! Mew!" << std::endl;
}

Brain&	Cat::getBrain(void) const{
	return *this->_brain;
}
