#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string	_name;
public:
	DiamondTrap(void);
	DiamondTrap(std::string const& name);
	DiamondTrap(DiamondTrap const& copy);
	DiamondTrap&	operator=(DiamondTrap const& add);
	~DiamondTrap(void);

	void whoAmI();

	using	ClapTrap::beRepaired;
	using	ClapTrap::takeDamage;
};

#endif
