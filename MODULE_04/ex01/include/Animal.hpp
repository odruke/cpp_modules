#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include "colors.hpp"
# include "Brain.hpp"

class Animal
{
protected:
	std::string _type;
public:
	Animal(void);
	Animal(Animal const& copy);
	virtual ~Animal(void);
	Animal&	operator=(Animal const& copy);

	virtual void	makeSound(void) const;

	std::string	getType(void) const;
	void	setType(std::string const& type);

	virtual Brain&	getBrain(void) const = 0;
};

#endif
