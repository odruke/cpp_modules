#include "Character.hpp"
#include "AMateria.hpp"

/* ========== Constructors and destructor ==============*/
Character::Character(std::string const& name) : _name(name){
	for (int i = 0; i < ARRAY_SIZE(this->_materias); i++){
		this->_materias[i] = NULL;
	}
	std::cout << ORANGE << "\nCharacter" << GREEN << " constructor by name called" << RESET << std::endl;
}

Character::Character(Character const& copy) : _name(copy._name){
	this->copy_materias(copy);
	std::cout << ORANGE << "\nCharacter" << GREEN << " constructor by copy called" << RESET << std::endl;
}

Character::~Character(void) {
	this->delete_materias();
	std::cout << ORANGE << "Character" << RED << " destructor called\n" << RESET << std::endl;
}

/* ============== assignment operator ============= */
Character&	Character::operator=(Character const& other){
	if (this == &other)
		return *this;
	this->_name = other._name;
	this->delete_materias();
	this->copy_materias(other);
	std::cout << ORANGE << "Character" << BLUE << " assignment operator called\n" << RESET << std::endl;
	return *this;
}

/* ============== getters and setters ============= */
std::string const&	Character::getName(void) const{
	return this->_name;
}

/* ============== member functions ============= */
void	Character::equip(AMateria* m){
	for (int i = 0; i < ARRAY_SIZE(this->_materias); i++){
		if (!this->_materias[i])
		{
			this->_materias[i] = m;
			break;
		}
	}
}

void	Character::unequip(int idx){
	if (idx < ARRAY_SIZE(this->_materias) && idx >= 0)
		this->_materias[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target){
	if (idx > ARRAY_SIZE(this->_materias) || idx < 0)
		return;
	if (this->_materias[idx])
		this->_materias[idx]->use(target);
}

void	Character::delete_materias(void){
	for (int i = 0; i < ARRAY_SIZE(this->_materias); i++){
		if (this->_materias[i])
		{
			delete this->_materias[i];
			this->_materias[i] = NULL;
		}
	}
}

void	Character::copy_materias(Character const& copy){
	for (int i = 0; i < ARRAY_SIZE(this->_materias); i++){
		if (copy._materias[i])
			this->_materias[i] = copy._materias[i]->clone();
		else
			this->_materias[i] = NULL;
	}
}
