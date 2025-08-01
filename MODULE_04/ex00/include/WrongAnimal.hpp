#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include "Animal.hpp"

class WrongAnimal : public Animal
{
public:
	WrongAnimal(void);
	WrongAnimal(WrongAnimal const& copy);
	~WrongAnimal(void);
	WrongAnimal&	operator=(WrongAnimal const& copy);

	virtual void	makeSound(void);
};

#endif
