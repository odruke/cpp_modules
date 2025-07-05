#include <iostream>
#include <cstdlib>

void	SafeGetLine(std::string& storage)
{
	std::getline(std::cin, storage);
	if (std::cin.eof()){
		std::cout << "\n\n\nEOF received: Exiting program now\nGood bye." << std::endl;
		exit(0);
	}
}
