#include "PhoneBook.hpp"
#include "Contact.hpp"

void	MainPrompt(void)
{
		std::cout << "Please, type a command to begin:\n" << std::endl;
		std::cout << "Adds a new contact" << std::setfill('-')
		<< std::setw(10) << std::right << ">[ADD]" << std::endl
		<< "Display the contact"
		<< std::setw(12) << std::right << ">[SEARCH]" << std::endl
		<< "Exits the program"
		<< std::setw(12) << std::right << ">[EXIT]" << std::endl;
		std::cout << std::setfill(' ') << "\n->";
}
int	main()
{
	PhoneBook phoneBook;
	std::string command;
	std::string tmp;

	std::cout << "\033[2J\033[1;1H";
	while (1)
	{
		MainPrompt();

		std::getline(std::cin, command);
		std::cout << "\033[2J\033[1;1H";
		if (command == "ADD"){
			phoneBook.AddContact();
		}
		else if (command == "SEARCH"){
			phoneBook.DisplayContacts();
		}
		else if (command == "EXIT")
			return 0;
		else{
			std::cout << "wrong command. Press enter to continue"
			<< std::endl;
			std::getline(std::cin, tmp);
		}
		std::cout << "\033[2J\033[1;1H";
	}





}
