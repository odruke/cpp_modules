#include "HumanA.hpp"

HumanA::HumanA(std::string newName, Weapon& myWeapon)
	: _myWeapon(myWeapon), _name(newName)
{
	return;
}

HumanA::~HumanA()
{
	return;
}

void HumanA::attack(void)
{
	std::cout
		<< HumanA::_name
		<< " attacks with their "
		<< _myWeapon.getType() << std::endl;
}
