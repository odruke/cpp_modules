#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap name constructor called" << std::endl;
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
	std::cout << "ClapTrap destructor called" << std::endl;
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
		std::cout << "it's already too late to repair, " << this->_name << " is gone" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << this->_name << " can't heal, he has no energy points!" << std::endl;
	else
	{
		std::cout
			<< this->_name << " restored " << ammount << " health points!"  << std::endl;
		this->_hitPoints += ammount;
		this->_energyPoints--;
	}
}

void	ClapTrap::takeDamage(unsigned int ammount)
{
	if (this->_hitPoints == 0)
		std::cout << "leave him alone! " << this->_name << " is already dead!" << std::endl;
	else
	{
		if (ammount >= this->_hitPoints)
		{
			this->_hitPoints = 0;
			std::cout << "Oh no!, you killed " << this->_name << " !!!" << std::endl;
		}
		else
		{
			this->_hitPoints -= ammount;
			std::cout << this->_name << " take " << ammount << " points of damage! "
			<< "it has only " << this->_hitPoints << " of health!" << std::endl;
		}
	}
}
