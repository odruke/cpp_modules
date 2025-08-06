#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain	*_brain;
public:
	Cat(void);
	Cat(Cat const& copy);
	virtual ~Cat(void);
	Cat&	operator=(Cat const& copy);

	void	makeSound(void) const;
};

#endif
