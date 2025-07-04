#include "HumanB.hpp"

HumanB::HumanB(std::string newName) : _name(newName)
{
	return;
}

HumanB::~HumanB()
{
	return;
}

void HumanB::attack(void)
{
	if (!this->_myWeapon.getType().empty()){
		std::cout << "i dont have a weapon to attack!" << std::endl;
	}
	std::cout
		<< HumanB::_name
		<< " attacks with their "
		<< _myWeapon.getType() << std::endl;
}

void	setWeapon(Weapon& newWeapon)
{
	this-> = &newWeapon;
}
