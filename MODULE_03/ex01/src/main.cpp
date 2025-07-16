#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()//refactor main
{
	ClapTrap	clappy("clappy");
	ScavTrap	scavy("skavy");
	int			repairAmmout = 8;

	clappy.attack(scavy.getName());
	scavy.takeDamage(clappy.getAttackDmg());
	scavy.beRepaired(repairAmmout);
	scavy.attack(clappy.getName());
	clappy.takeDamage(scavy.getAttackDmg());
	clappy.beRepaired(repairAmmout);
	scavy.guardGate();

}
