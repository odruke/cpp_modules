#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->n_contacts = 0;
	FullMemory = false;
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

bool	PhoneBook::FullContacts(void)
{
	std::string prompt;
	std::cout << "MEMORY FULL! Warning:"
	<< " adding a new contact will reset the contact n. " << n_contacts + 1 << ".\n"
	<< std::endl;
	std::cout << "You want to delete the old contact and enter a new one?" << std::endl;
	std::cout << "[YES]|[NO]";

	do{
		std::getline(std::cin, prompt);
		if (!prompt.compare("YES")){
			std::cout << "\033[2J\033[1;1H";
			return false;
		}

		else if (!prompt.compare("NO"))
			return true;
		else
			std::cout << "please, type \"YES\" or \"NO\" in the console" << std::endl;
	}while(1);
}
void	PhoneBook::AddContact(void)
{
	if (n_contacts > 7){
		FullMemory = true;
		this->n_contacts = 0;
	}
	if (FullMemory)
		if (PhoneBook::FullContacts())
			return;
	Contact contact(n_contacts);
	this->contacts[n_contacts] = contact;
	this->n_contacts++;
}

void	PhoneBook::DisplayContacts(void)
{
	std::string tmp;
	int			contactCounter;

	if (this->FullMemory)
		contactCounter = 8;
	else
		contactCounter = this->n_contacts;
	if (!contactCounter){
		std::cout << "The Phone book is empty. Press enter to continue"
		<< std::endl;
		std::getline(std::cin, tmp);
		return;
	}
	std::cout << "|" << "..........";
	std::cout << "|" << "..........";
	std::cout << "|" << "..........";
	std::cout << "|" << ".........." << "|" << std::endl;
	std::cout << "|  INDEX   |FIRST NAME|LAST NAME | NICKNAME |" << std::endl;
	std::cout << "|" << "..........";
	std::cout << "|" << "..........";
	std::cout << "|" << "..........";
	std::cout << "|" << ".........." << "|" << std::endl;

	for (int i = 0; i < contactCounter; i++){
		std::cout
		<< "|" << std::setw(10) << std::right << contacts[i].GetField(IDX)
		<< "|" << std::setw(10) << std::right << contacts[i].GetField(FIRSTNAME)
		<< "|" << std::setw(10) << std::right << contacts[i].GetField(LASTNAME)
		<< "|" << std::setw(10) << std::right << contacts[i].GetField(NICKNAME)
		<< "|" << std::endl;
	}

	std::cout << "|" << "..........";
	std::cout << "|" << "..........";
	std::cout << "|" << "..........";
	std::cout << "|" << ".........." << "|\n\n" << std::endl;

	PhoneBook::SearchContact();
}

void	PhoneBook::SearchContact(void)
{
	std::string	idxInput;
	int			idx;
	bool		inputOk = true;
	int			contactCounter;

	if (this->FullMemory)
		contactCounter = 8;
	else
		contactCounter = this->n_contacts;
	do{
		inputOk = true;
		std::cout << "Type an index contact to show info, or press enter to return to menu: ";
		std::getline(std::cin, idxInput);
		if (idxInput.empty())
			return;
		std::stringstream index(idxInput);
		index >> idx;
		if (idx < 1 || idx > contactCounter || idxInput.length() > 1){
			inputOk = false;
			std::cout << "\x1B[1A"
			<< "\x1B[2K"
			<< "\x1B[0G"
			<< "you must enter an index contact from 1 to " << contactCounter << std::endl;
		}
		}while(!inputOk);
		std::cout << std::endl;
		this->contacts[idx - 1].PrintContact();
}
