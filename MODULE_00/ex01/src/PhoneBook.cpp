#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	_FullMemory = false;
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
	<< " adding a new contact will reset the contact n. " << Contact::getNbContacts() + 1 << ".\n"
	<< std::endl;
	std::cout << "You want to delete the old contact and enter a new one?" << std::endl;
	std::cout << "[YES]|[NO]";

	do{
		SafeGetLine(prompt);
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
	int nb = Contact::getNbContacts();

	if (nb > 7){
		_FullMemory = true;
		Contact::setNbContacts(0);
		nb = 0;
	}
	if (_FullMemory){
		if (PhoneBook::FullContacts())
			return;
	}
	Contact contact(nb);
	this->_contacts[nb] = contact;
	Contact::setNbContacts(nb + 1);
}

void	PhoneBook::DisplayContacts(void)
{
	std::string tmp;
	int			contactCounter;


	if (this->_FullMemory)
		contactCounter = 8;
	else
		contactCounter = Contact::getNbContacts();
	if (!contactCounter){
		std::cout << "The Phone book is empty. Press enter to continue"
		<< std::endl;
		SafeGetLine(tmp);
		return;
	}
	std::cout << std::setfill(SPACER)
		<< "|" << std::setw(11)
		<< "|" << std::setw(11)
		<< "|" << std::setw(11)
		<< "|" << std::setw(11)
		<< "|" << std::endl;

	std::cout << "|  INDEX   |FIRST NAME|LAST NAME | NICKNAME |" << std::endl;

	std::cout
		<< "|" << std::setw(11)
		<< "|" << std::setw(11)
		<< "|" << std::setw(11)
		<< "|" << std::setw(11)
		<< "|" << std::setfill(' ') << std::endl;

	for (int i = 0; i < contactCounter; i++){
		std::cout
		<< "|" << std::setw(10) << std::right << _contacts[i].getField(IDX)
		<< "|" << std::setw(10) << std::right << _contacts[i].getField(FIRSTNAME)
		<< "|" << std::setw(10) << std::right << _contacts[i].getField(LASTNAME)
		<< "|" << std::setw(10) << std::right << _contacts[i].getField(NICKNAME)
		<< "|" << std::endl;
	}

	std::cout << std::setfill(SPACER)
		<< "|" << std::setw(11)
		<< "|" << std::setw(11)
		<< "|" << std::setw(11)
		<< "|" << std::setw(11)
		<< "|" << std::setfill(' ') << "\n\n"<< std::endl;

	PhoneBook::SearchContact();
}

void	PhoneBook::SearchContact(void)
{
	std::string	idxInput;
	int			idx;
	bool		inputOk = true;
	int			contactCounter;

	if (this->_FullMemory)
		contactCounter = 8;
	else
		contactCounter = Contact::getNbContacts();
	do{
		inputOk = true;
		std::cout << "Type an index contact to show info, or press enter to return to menu: ";
		SafeGetLine(idxInput);
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
		this->_contacts[idx - 1].PrintContact();
}
