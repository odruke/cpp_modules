#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
	: ClapTrap(+ "_clap_name"), ScavTrap(), FragTrap(), _name("defDiamond")
{
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;

	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string const& name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;

	std::cout << "DiamondTrap constructor by name called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const& copy)
	: ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	*this = copy;
	std::cout << "DiamondTrap constructor by copy called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const& add)
{
	this->_name = add._name;
	this->_attackDamage = add._attackDamage;
	this->_energyPoints = add._energyPoints;
	this->_hitPoints = add._hitPoints;
	std::cout << "DiamondTrap asignation overload called" << std::endl;

	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

/* subject functions */

void	DiamondTrap::whoAmI(void)
{
	std::cout << "My name is: " << this->_name << std::endl;
	std::cout << "My ClapTrap name is: " << ClapTrap::_name << std::endl;
}


