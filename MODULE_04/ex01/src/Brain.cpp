#include "Brain.hpp"

Brain::Brain(void){
	for (int i = 0; i < 100; i++){
		std::stringstream ss;
		ss << "idea n" << i;
		this->_ideas[i] = ss.str();
	}
	std::cout << WHITE << "Brain" << GREEN << " constructor called" << RESET << std::endl;
}

Brain::Brain(Brain const& copy) : _ideas(copy._ideas){
	std::cout << WHITE << "Brain" << GREEN << " constructor by copy called" << RESET << std::endl;
}

Brain::~Brain(){
	std::cout << WHITE << "Brain" << RED << " destructor called" << RESET << std::endl;
}

Brain&	Brain::operator=(Brain const& other)
{
	if (this != &other)
		this->_ideas = other._ideas;
	return *this;
}
