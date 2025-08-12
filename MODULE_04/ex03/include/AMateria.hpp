#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include "colors.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string	_type;
public:
	AMateria(void);
	AMateria(std::string const& type);
	AMateria(AMateria const& copy);
	virtual ~AMateria();
	AMateria&	operator=(AMateria const& other);

	std::string const & getType(void) const;

	virtual AMateria* clone() const = 0; // to implement?
	virtual void use(ICharacter& target); // to implement?
};

#endif
