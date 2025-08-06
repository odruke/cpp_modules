#include "Brain.hpp"

/* ================ Constructors and destructor ============== */
Brain::Brain(void){
	std::cout << WHITE << "Brain" << GREEN << " constructor called" << RESET << std::endl;
}

Brain::Brain(Brain const& copy) : _ideas(copy._ideas){
	std::cout << WHITE << "Brain" << GREEN << " constructor by copy called" << RESET << std::endl;
}

Brain::~Brain(){
	std::cout << WHITE << "Brain" << RED << " destructor called" << RESET << std::endl;
}

/* =================== assignment operator ================ */
Brain&	Brain::operator=(Brain const& other)
{
	if (this != &other){
		for (int i = 0; i < 100; i++){
			this->_ideas[i] = other._ideas[i];
		}
	}
	std::cout << WHITE << "Brain" << CYAN << " assignment operator called" << RESET << std::endl;
	return *this;
}

/* ============== getters and setters ============= */
std:: string const&	Brain::getIdea(int const& index) const{
	if (index >= 0 && index < 100)
		return this->_ideas[index];
	return this->_ideas[0];
}

void	Brain::setIdea(std::string const& newIdea, int const& index){
	if (index >= 0 && index < 100)
		this->_ideas[index] = newIdea[index];
}
