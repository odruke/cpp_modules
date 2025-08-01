#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const& copie);
	ScavTrap&	operator=(ScavTrap const& add);
	~ScavTrap(void);

	void attack(const std::string& target);
	void guardGate(void);
};

#endif
