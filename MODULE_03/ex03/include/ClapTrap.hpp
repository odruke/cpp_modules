#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# ifndef HISTORY
#define HISTORY 0
#endif

# define RESET		"\033[0m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

#include <iostream>

class ClapTrap
{
protected:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const& copie);
	ClapTrap&	operator=(ClapTrap const& add);
	~ClapTrap(void);

	std::string	getName(void) const;
	int getHp(void) const;
	int getEnergyP(void) const;
	int getAttackDmg(void) const;

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
