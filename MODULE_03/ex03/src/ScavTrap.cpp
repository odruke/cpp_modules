#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_attackDamage = 20;
	this->_energyPoints = 50;
	this->_hitPoints = 100;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap()
{
	this->_name = name;
	this->_attackDamage = 20;
	this->_energyPoints = 50;
	this->_hitPoints = 100;
	std::cout << "ScavTrap name constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& add): ClapTrap() {*this = add;}

ScavTrap&	ScavTrap::operator=(ScavTrap const& add)
{
	this->_name = add._name;
	this->_hitPoints = add._hitPoints;
	this->_energyPoints = add._energyPoints;
	this->_attackDamage = add._attackDamage;
	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

/* subject functions */

void	ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
		std::cout
			<< "CL4P-TP unit type ScapTrap \""
			<< this->_name << "\" can't attack, he is in a better place now" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout
			<< "CL4P-TP unit type ScapTrap \""
			<< this->_name << "\" can't attack, he has no energy points!" << std::endl;
	else
	{
		std::cout
			<< "CL4P-TP unit type ScapTrap \""
			<< this->_name << "\" attacks " << target
			<< " causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << this->_name << " is now on gatekeeper mode! whatever that means..." << std::endl;
}

