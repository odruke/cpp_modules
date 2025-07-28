#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_attackDamage = 20;
	this->_energyPoints = 50;
	this->_hitPoints = 100;
	std::cout << YELLOW << "ScavTrap" << GREEN << " default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_name = name;
	this->_attackDamage = 20;
	this->_energyPoints = 50;
	this->_hitPoints = 100;
	std::cout << YELLOW << "ScavTrap" << GREEN << " constructor by name called" << RESET << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& add): ClapTrap(add) {*this = add;}

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
	std::cout << YELLOW << "ScavTrap"  << RED << " destructor called" << RESET << std::endl;
}

/* subject functions */

void	ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
		std::cout
			<< YELLOW << "ScapTrap " << CYAN << "\""
			<< this->_name << "\"" << RESET << " can't attack, he is in a better place now" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout
			<< YELLOW << "ScavTrap " << CYAN << "\""
			<< this->_name << "\"" << RESET << " can't attack, he has no energy points!" << std::endl;
	else
	{
		std::cout
			<< YELLOW << "ScapTrap " << CYAN << "\""
			<< this->_name << "\"" WHITE " attacks " << RED << target << WHITE
			<< " causing " << RED << this->_attackDamage << RESET << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << CYAN << this->_name << RESET << " is now on gatekeeper mode! whatever that means..." << std::endl;
}

