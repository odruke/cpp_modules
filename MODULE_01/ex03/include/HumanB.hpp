#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <Weapon.hpp>

class HumanB
{
private:
	std::string	_name;
	Weapon*		_myWeapon;
public:
	HumanB(std::string newName);
	~HumanB();
	void	attack(void);
	void	setWeapon(Weapon& newWeapon);

};

#endif
