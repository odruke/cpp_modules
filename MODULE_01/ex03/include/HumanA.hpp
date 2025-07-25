#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
	std::string	_name;
	Weapon&		_myWeapon;
public:
	HumanA(std::string newName, Weapon& myWeapon);
	~HumanA();

	void	attack(void);
};

#endif
