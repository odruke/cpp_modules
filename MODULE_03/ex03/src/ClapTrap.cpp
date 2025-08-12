#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	this->_initialHp = _hitPoints;
	std::cout << WHITE << "ClapTrap" << GREEN << " default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	this->_initialHp = _hitPoints;
	std::cout << WHITE << "ClapTrap" << GREEN << " constructor by name called" << RESET << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& add){*this = add;}

ClapTrap&	ClapTrap::operator=(ClapTrap const& add)
{
	if (this != &add)
	{
		this->_name = add._name;
		this->_hitPoints = add._hitPoints;
		this->_energyPoints = add._energyPoints;
		this->_attackDamage = add._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << WHITE << "ClapTrap"  << RED << " destructor called" << RESET << std::endl;
}

/* getters */
std::string	ClapTrap::getName(void) const {return this->_name;}
int	ClapTrap::getHp(void) const {return this->_hitPoints;}
int	ClapTrap::getEnergyP(void) const {return this->_energyPoints;}
int	ClapTrap::getAttackDmg(void) const {return this->_attackDamage;}

/* subject functions */

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
		std::cout << this->_name << " can't attack, he is in a better place now" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << this->_name << " can't attack, he has no energy points!" << std::endl;
	else
	{
		std::cout
			<< this->_name << " attacks " << target
			<< " causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void	ClapTrap::beRepaired(unsigned int ammount)
{
	if (this->_hitPoints == 0)
		std::cout << "it's already too late to repair, " << CYAN << this->_name << RESET << " is gone" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << CYAN << this->_name << RESET << " can't heal, he has no energy points!" << std::endl;
	else
	{
		std::cout
			 << CYAN << this->_name << RESET << " restored " << GREEN << ammount << RESET << " health points!"  << std::endl;
		this->_hitPoints += ammount;
		this->_energyPoints--;
	}
}

void	ClapTrap::takeDamage(unsigned int ammount)
{
	if (this->_hitPoints == 0)
		std::cout << "leave him alone! " << CYAN << this->_name << RESET << " is already dead!" << std::endl;
	else
	{
		if (ammount >= this->_hitPoints)
		{
			this->_hitPoints = 0;
			std::cout << "Oh no!, you killed " << CYAN << this->_name << RESET << " !!!" << std::endl;
		}
		else
		{
			this->_hitPoints -= ammount;
			std::cout << CYAN << this->_name << RESET << " take " << RED << ammount << RESET << " points of damage! "
			<< "it has only " << MAGENTA << this->_hitPoints << RESET << " of health!" << std::endl;
		}
	}
}

int	ClapTrap::getInitialHp(void) const {return this->_initialHp;}
