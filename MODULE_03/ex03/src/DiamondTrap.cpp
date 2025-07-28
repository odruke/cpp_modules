#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
	: ClapTrap("defDiamond_clap_name"), ScavTrap(), FragTrap(), _name("defDiamond")
{
	this->_hitPoints = FragTrap::_hitPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	this->_energyPoints = ScavTrap::_energyPoints;

	std::cout << CYAN << "DiamondTrap" << GREEN << " default constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string const& name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name + "_Scav_name"), FragTrap(name + "_Frag_name"), _name(name)
{
	this->_hitPoints = FragTrap::_hitPoints;
	std::cout << this->_hitPoints << " : " << FragTrap::_hitPoints << std::endl;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << this->_attackDamage << " : " << FragTrap::_attackDamage << std::endl;
	this->_energyPoints = ScavTrap::_energyPoints;
	std::cout << this->_energyPoints << " : " << ScavTrap::_energyPoints << std::endl;


	std::cout << CYAN << "DiamondTrap" << GREEN << " constructor by name called" << RESET << std::endl;

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
	std::cout << CYAN << "DiamondTrap"  << RED << " destructor called" << RESET << std::endl;
}

/* subject functions */

void	DiamondTrap::whoAmI(void)
{
	std::cout << "\nMy name is: " << GREEN << this->_name << RESET << std::endl;
	std::cout << "My ClapTrap name is: " << CYAN << ClapTrap::_name << RESET << std::endl;
}


