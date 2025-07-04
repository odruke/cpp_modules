#include "Weapon.hpp"

Weapon::Weapon(void)
{
	return;
}

Weapon::~Weapon()
{
	return;
}

std::string	Weapon::getType(void) const
{
	return this->type;
}

void	Weapon::setType(std::string newType)
{
	this->type = newType;
}
