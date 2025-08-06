#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include "colors.hpp"

class WrongAnimal
{
protected:
	std::string _type;
public:
	WrongAnimal(void);
	WrongAnimal(WrongAnimal const& copy);
	virtual ~WrongAnimal(void);
	WrongAnimal&	operator=(WrongAnimal const& copy);

	virtual void	makeSound(void) const;

	std::string	getType(void) const;
	void	setType(std::string const& type);
};

#endif
