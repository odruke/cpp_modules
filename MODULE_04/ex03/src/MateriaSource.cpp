#include "MateriaSource.hpp"

/* ========== Constructors and destructor ==============*/
MateriaSource::MateriaSource(void){
	for (int i = 0; i < ARRAY_SIZE(this->_materias); i++){
		this->_materias[i] = NULL;
	}
	std::cout << MAGENTA << "MateriaSource" << GREEN << " constructor by name called" << RESET << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const& copy){
	this->copy_materias(copy);
	std::cout << MAGENTA << "MateriaSource" << GREEN << " constructor by copy called" << RESET << std::endl;
}

MateriaSource::~MateriaSource(void){
	this->delete_materias();
	std::cout << MAGENTA << "MateriaSource" << RED << " destructor called" << RESET << std::endl;
}

/* ============== assignment operator ============= */
MateriaSource&	MateriaSource::operator=(MateriaSource const& other){
	if (this == &other)
		return *this;
	this->delete_materias();
	this->copy_materias(other);
	std::cout << MAGENTA << "MateriaSource" << BLUE << " assignment operator called" << RESET << std::endl;
	return *this;
}

/* ============== member functions ============= */
void	MateriaSource::delete_materias(void){
	for (int i = 0; i < ARRAY_SIZE(this->_materias); i++){
		if (this->_materias[i])
		{
			delete this->_materias[i];
			this->_materias[i] = NULL;
		}
	}
}

void	MateriaSource::copy_materias(MateriaSource const& copy){
	for (int i = 0; i < ARRAY_SIZE(this->_materias); i++){
		if (copy._materias[i])
			this->_materias[i] = copy._materias[i]->clone();
		else
			this->_materias[i] = NULL;
	}
}

void	MateriaSource::learnMateria(AMateria* materia){
	for (int i = 0; i < ARRAY_SIZE(this->_materias); i++){
		if (!this->_materias[i])
		{
			this->_materias[i] = materia;
			break;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < ARRAY_SIZE(this->_materias); i++){
		if (this->_materias[i] && this->_materias[i]->getType() == type)
			return this->_materias[i]->clone();
	}
	return 0;
}
