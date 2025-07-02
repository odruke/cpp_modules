#include "Contact.hpp"
bool	ValidPhone(std::string number)
{
	if (number.empty())
		return true;
	if (number.length() > 16 || number.length() < 9)
		return false;
	for (size_t i = 0; i < number.length(); i++){
		if (i == 0 &&number[i] == '+')
			i++;
		if (number[i] == ' ' && i != 0)
			i++;
		if (!std::isdigit(number[i]))
			return false;
	}
	return true;
}
Contact::Contact(void)
{
	_firstName = "";
	_lastName = "";
	_nickName = "";
	_darkestSecret = "";
	_idx = 0;
	return;
}

Contact::Contact(int ide)
{
	Contact::NewContact(ide);
	Contact::_nbContacts += 1;
	return;
}

Contact::~Contact(void)
{
	return;
}

void Contact::NewContact(int	ide)
{
	/*loop the prompt until the user inputs a valid name*/
	do {
		std::cout << "First name: ";
		std::getline(std::cin, _firstName);
		if (_firstName.empty())
			std::cout << "We need at least a name!" << std::endl;
	}while (_firstName.empty());

	std::cout << "Last name: ";
	std::getline(std::cin, _lastName);

	std::cout << "Nickname: ";
	std::getline(std::cin, _nickName);

	/*loop the prompt until the user inputs a valid number*/
	bool OnlyNumbers;
	do{
		OnlyNumbers = true;
		std::cout << "Phone number: ";
		std::getline(std::cin, _phoneNumber);
		OnlyNumbers = ValidPhone(_phoneNumber);
		if (!OnlyNumbers)
			std::cout << "Please enter a valid phone number" << std::endl;
	}while (!OnlyNumbers);

	std::cout << "Enter your darkest secret: ";
	std::getline(std::cin, _darkestSecret);
	this->_idx = ide;
}

void	Contact::PrintContact(void)
{
	std::string	tmp;
	std::cout << "First name: " << this->_firstName << std::endl;
	std::cout << "Last name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickName << std::endl;
	std::cout << "Phone numer: " << this->_phoneNumber << std::endl;
	std::cout << "Your darkest secret is: " << this->_darkestSecret << std::endl;
	std::cout << "\n\npress enter to continue" << std::endl;
	std::getline(std::cin, tmp);
}

std::string Contact::getField(e_ContactMember field) const
{
	std::string value;
	switch (field)
	{
		case FIRSTNAME:
			value = this->_firstName;
			break;
		case LASTNAME:
			value = this->_lastName;
			break;
		case NICKNAME:
			value = this->_nickName;
			break;
		case PHONENUMBER:
			value = this->_phoneNumber;
			break;
		case DARKESTSECRET:
			value = this->_darkestSecret;
			break;
		case IDX:
			std::stringstream ss;
			ss << _idx + 1;
			value = ss.str();
	}
	if (value.length() > 10)
		return (value.substr(0, 9) + ".");
	return value;
}

int	Contact::getNbContacts(void)
{
	return Contact::_nbContacts;
}

void	Contact::setNbContacts(int newNb)
{
	Contact::_nbContacts = newNb;
}

int	Contact::_nbContacts = 0;
