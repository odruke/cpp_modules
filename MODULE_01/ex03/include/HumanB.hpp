#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>

class HumanB
{
private:
	std::string	_name;
	Weapon		_myWeapon;
public:
	HumanB(std::string newName);
	~HumanB();
};

#endif
