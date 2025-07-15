#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
#include <iostream>

class ClapTrap
{
private:
	std::string	_name;
	unsigned int			_hitPoints;
	unsigned int			_energyPoints;
	unsigned int			_attackDamage;
public:
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const& copie);
	ClapTrap&	operator=(ClapTrap const& add);
	~ClapTrap(void);

	std::string	getName(void);
	int getHp(void);
	int getEnergyP(void);
	int getAttackDmg(void);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
