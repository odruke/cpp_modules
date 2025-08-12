#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# define ARRAY_SIZE(array)((int)(sizeof(array) / sizeof(array[0])))
# include "Character.hpp"
# include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource
{
private:
	AMateria	*_materias[4];
	void		delete_materias(void);
	void		copy_materias(MateriaSource const& copy);
public:
	MateriaSource();
	MateriaSource(MateriaSource const& copy);
	virtual ~MateriaSource();
	MateriaSource&	operator=(MateriaSource const& other);

	virtual void learnMateria(AMateria* materia);
	virtual AMateria* createMateria(std::string const & type);
};

#endif
