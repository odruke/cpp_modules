#include "HumanB.hpp"

HumanB::HumanB(std::string newName) : _name(newName), _myWeapon(NULL)
{
	return;
}

HumanB::~HumanB()
{
	return;
}

void HumanB::attack(void)
{
	if (_myWeapon){
			std::cout
		<< HumanB::_name
		<< " attacks with their "
		<< _myWeapon->getType() << std::endl;
	}
	else
		std::cout << "i dont have a weapon to attack!" << std::endl;
}


void	HumanB::setWeapon(Weapon& newWeapon)
{
	this->_myWeapon = &newWeapon;
}
