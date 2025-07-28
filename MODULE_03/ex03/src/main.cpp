#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{
	ClapTrap	clappy("clappy");
	std::cout << std::endl;
	ScavTrap	scavy("skavy");
	std::cout << std::endl;
	FragTrap	fraggy("chtulhu destroyer of worlds");
	std::cout << std::endl;
	DiamondTrap	weird("weirdo");

	int			repairAmmout = 8;

	std::cout << "\n" << std::endl;
if (HISTORY)
{
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
}


	std::cout
		<< weird.getName() << " hit points is: " << weird.getHp()
		<< ", same as FragTrap: " << fraggy.getHp() << "\n" << std::endl;
	std::cout
		<< weird.getName() << " energy is: " << weird.getEnergyP()
		<< ", same as ScavTrap: " << scavy.getEnergyP() << "\n" << std::endl;
	std::cout
		<< weird.getName() << " attack is: " << weird.getAttackDmg()
		<< ", same as FragTrap: " << fraggy.getAttackDmg() << "\n" << std::endl;


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
