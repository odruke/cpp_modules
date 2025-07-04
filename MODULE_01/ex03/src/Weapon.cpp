#include "Weapon.hpp"

Weapon::Weapon(void)
{
	return;
}

Weapon::Weapon(std::string newType) : _type(newType)
{
	return;
}

Weapon::~Weapon()
{
	return;
}

std::string	Weapon::getType(void) const
{
	return this->_type;
}

void	Weapon::setType(std::string newType)
{
	this->_type = newType;
}
