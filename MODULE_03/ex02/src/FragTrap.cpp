#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_attackDamage = 30;
	this->_energyPoints = 100;
	this->_hitPoints = 100;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string const& name) : ClapTrap(name)
{
	this->_name = name;
	this->_attackDamage = 30;
	this->_energyPoints = 100;
	this->_hitPoints = 100;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const& add): ClapTrap(add) {*this = add;}

FragTrap&	FragTrap::operator=(FragTrap const& add)
{
	this->_name = add._name;
	this->_hitPoints = add._hitPoints;
	this->_energyPoints = add._energyPoints;
	this->_attackDamage = add._attackDamage;
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

/* subject functions */

void	FragTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
		std::cout
			<< "The infamous CL4P-TP unit type FragTrap \""
			<< this->_name << "\" can't attack, he is in a better place now" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout
			<< "The infamous CL4P-TP unit type FragTrap \""
			<< this->_name << "\" can't attack, he has no energy points!" << std::endl;
	else
	{
		std::cout
			<< "The infamous CL4P-TP unit type FragTrap \""
			<< this->_name << "\" attacks " << target
			<< " causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << this->_name << ": Gimme five!" << std::endl;
}


