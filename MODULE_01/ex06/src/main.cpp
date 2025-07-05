#include "Harl.hpp"
#include <cstdlib>

void	SafeGetLine(std::string& storage);

int	main(int ac, char **av)
{
	Harl 		harl;
	std::string	input;
	if (ac != 2){
		std::cout
			<< "Wrong parameters. Usage:\n./Harl [level]\n(DEBUG, INFO, WARNING, ERROR)"
			<< std::endl;
		return EXIT_FAILURE;
	}
	input = av[1];
	harl.complain(input);

	return EXIT_SUCCESS;
}
