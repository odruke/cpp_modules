#include <iostream>
#include <iomanip>


int	main()
{
	std::string		brain = "HI THIS IS BRAIN";

	std::string*	stringPTR = &brain;
	std::string&	stringREF = brain;

	std::cout
		<< std::setw(50) << std::left << "this is the address of brain"
		<< std::setw(17) << std::right << &brain << std::endl
		<< std::setw(50) << std::left << "this is the aDdress held in the pointer stringPTR"
		<< std::setw(17) << std::right << stringPTR << std::endl
		<< std::setw(50) << std::left << "this is the aDdress held the pointer stringREF"
		<< std::setw(17) << std::right << &stringREF << std::endl;

	std::cout
		<< std::setw(44) << std::left << "\nthis is the value of brain"
		<< std::setw(17) << std::right << brain << std::endl
		<< std::setw(43) << std::left << "this is the value of pointer stringPTR"
		<< std::setw(17) << std::right << *stringPTR << std::endl
		<< std::setw(43) << std::left << "this is the value of stringREF"
		<< std::setw(17) << std::right << stringREF << std::endl;
}
