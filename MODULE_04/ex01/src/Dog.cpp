#include "Dog.hpp"

/* ============= Constructors and destructor ============ */
Dog::Dog(void) : Animal(), _brain(new Brain()) {
	if (!this->_brain){
			std::cout << "brain allocation failed at: " << __FILE__ << ", " << __LINE__ << std::endl;
			exit(1);
	}
	for (int i = 0; i < MAX_IDEAS; i++){
		std::stringstream ss;
		ss << "dog thought n" << i;
		_brain->setIdea(ss.str(), i);
	}
	this->_type = "Dog";
	std::cout << BLUE << "Dog" << GREEN << " constructor called" << RESET << std::endl;
}

Dog::Dog(Dog const& copy) : Animal(copy), _brain(new Brain()){
	if (!this->_brain){
			std::cout << "brain allocation failed at: " << __FILE__ << ", " << __LINE__ << std::endl;
			exit(1);
	}
	for (int i = 0; i < MAX_IDEAS; i++){
		_brain->setIdea(copy._brain->getIdea(i), i);
	}
	std::cout << BLUE << "Dog" << GREEN << " constructor by copy called" << RESET << std::endl;
}

Dog::~Dog(void){
	delete _brain;
	std::cout << BLUE << "Dog" << RED << " destructor called" << RESET << std::endl;
}

/* ============= assignment operator ===================*/
Dog&	Dog::operator=(Dog const& copy){
	if (this != &copy){
		Animal::operator=(copy);
		delete this->_brain;
		this->_brain = new Brain();
		for (int i = 0; i < MAX_IDEAS; i++){
		_brain->setIdea(copy._brain->getIdea(i), i);
		}
	}
	std::cout << BLUE << "Dog" << CYAN << " assignment operator called" << RESET << std::endl;
	return *this;
}

/* ============== member functions ============= */
void	Dog::makeSound(void) const{
	std::cout << BLUE << this->_type << RESET << ": Woof!, Woof!" << std::endl;
}

Brain&	Dog::getBrain(void) const{
	return *this->_brain;
}
