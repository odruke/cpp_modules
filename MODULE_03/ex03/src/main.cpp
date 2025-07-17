#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{
	ClapTrap	clappy("clappy");
	ScavTrap	scavy("skavy");
	FragTrap	fraggy("chtulhu destroyer of worlds");
	DiamondTrap	weird("weirdo");

	int			repairAmmout = 8;

	std::cout << "\n" << std::endl;

	clappy.attack(scavy.getName());
	std::cout << std::endl;
	scavy.takeDamage(clappy.getAttackDmg());
	std::cout << std::endl;
	scavy.beRepaired(repairAmmout);
	std::cout << std::endl;
	scavy.attack(clappy.getName());
	std::cout << std::endl;
	clappy.takeDamage(scavy.getAttackDmg());
	std::cout << std::endl;
	clappy.beRepaired(repairAmmout);
	std::cout << std::endl;
	scavy.guardGate();
	std::cout << "\n" << std::endl;

	fraggy.attack(scavy.getName());
	std::cout << std::endl;
	scavy.takeDamage(fraggy.getAttackDmg());
	std::cout << std::endl;
	fraggy.attack(scavy.getName());
	std::cout << std::endl;
	scavy.takeDamage(fraggy.getAttackDmg());
	std::cout << std::endl;
	fraggy.attack(scavy.getName());
	std::cout << std::endl;
	scavy.takeDamage(fraggy.getAttackDmg());
	std::cout << std::endl;
	fraggy.attack(scavy.getName());
	std::cout << std::endl;
	scavy.takeDamage(fraggy.getAttackDmg());
	std::cout << "\n" << std::endl;
	fraggy.highFivesGuys();
	std::cout << "\n" << std::endl;


	weird.FragTrap::attack("no one");
	weird.ScavTrap::attack("nobody");
	weird.attack("nobody again");
	weird.takeDamage(0);
	weird.beRepaired(repairAmmout);
	weird.guardGate();
	weird.highFivesGuys();
	weird.whoAmI();

	std::cout << "\n" << std::endl;
}
