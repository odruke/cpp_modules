#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain	*_brain;
public:
	Dog(void);
	Dog(Dog const& copy);
	~Dog(void);
	Dog&	operator=(Dog const& copy);

	void	makeSound(void) const;
};




#endif
