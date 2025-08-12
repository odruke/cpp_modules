#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# define ARRAY_SIZE(array)((int)(sizeof(array) / sizeof(array[0])))
# include "ICharacter.hpp"
# include "colors.hpp"


class AMateria;

class	Character : public ICharacter
{
private:
	std::string	_name;
	AMateria 	*_materias[4];
	void		delete_materias(void);
	void		copy_materias(Character const& copy);
public:
	Character(std::string const& name);
	Character(Character const& copy);
	virtual ~Character();
	Character&	operator=(Character const& other);

	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};

# endif
