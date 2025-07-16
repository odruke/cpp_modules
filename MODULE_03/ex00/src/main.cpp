#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	clappy("clappy");

	std::cout << "\n" << std::endl;

	clappy.attack("coughing baby");
	clappy.takeDamage(9);
	clappy.beRepaired(8);
	clappy.takeDamage(8);
	clappy.beRepaired(8);
	clappy.takeDamage(8);
	clappy.beRepaired(8);
	clappy.takeDamage(8);
	clappy.beRepaired(8);
	clappy.takeDamage(7);
	clappy.attack("coughing baby");
	clappy.beRepaired(8);
	clappy.takeDamage(7);
	clappy.attack("coughing baby");
	clappy.attack("coughing baby");
	clappy.beRepaired(8);
	clappy.takeDamage(7);
	clappy.attack("coughing baby");
	clappy.beRepaired(8);
	clappy.takeDamage(7);
	clappy.takeDamage(7);
	clappy.beRepaired(8);
	clappy.attack("coughing baby");

	std::cout << "\n" << std::endl;
}
