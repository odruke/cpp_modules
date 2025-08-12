#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
public:
	Ice(void);
	Ice(Ice const& copy);
	~Ice(void);
	Ice&	operator=(Ice const& other);

	AMateria* clone() const;
	void	use(ICharacter& target);
};

#endif
