#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat(void);
	WrongCat(WrongCat const& copy);
	~WrongCat(void);
	WrongCat&	operator=(WrongCat const& copy);

	virtual void	makeSound(void) const;
};

#endif
