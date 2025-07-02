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
	FirstName = "";
	LastName = "";
	NickName = "";
	DarkestSecret = "";
	idx = 0;
	return;
}

Contact::Contact(int ide)
{
	Contact::NewContact(ide);
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
		std::getline(std::cin, FirstName);
		if (FirstName.empty())
			std::cout << "We need at least a name!" << std::endl;
	}while (FirstName.empty());

	std::cout << "Last name: ";
	std::getline(std::cin, LastName);

	std::cout << "Nickname: ";
	std::getline(std::cin, NickName);

	/*loop the prompt until the user inputs a valid number*/
	bool OnlyNumbers;
	do{
		OnlyNumbers = true;
		std::cout << "Phone number: ";
		std::getline(std::cin, PhoneNumber);
		OnlyNumbers = ValidPhone(PhoneNumber);
		if (!OnlyNumbers)
			std::cout << "Please enter a valid phone number" << std::endl;
	}while (!OnlyNumbers);

	std::cout << "Enter your darkest secret: ";
	std::getline(std::cin, DarkestSecret);
	this->idx = ide;
}

void	Contact::PrintContact(void)
{
	std::string	tmp;
	std::cout << "First name: " << this->FirstName << std::endl;
	std::cout << "Last name: " << this->LastName << std::endl;
	std::cout << "Nickname: " << this->NickName << std::endl;
	std::cout << "Phone numer: " << this->PhoneNumber << std::endl;
	std::cout << "Your darkest secret is: " << this->DarkestSecret << std::endl;
	std::cout << "\n\npress enter to continue" << std::endl;
	std::getline(std::cin, tmp);
}

std::string Contact::GetField(e_ContactMember field) const
{
	std::string value;
	switch (field)
	{
		case FIRSTNAME:
			value = this->FirstName;
			break;
		case LASTNAME:
			value = this->LastName;
			break;
		case NICKNAME:
			value = this->NickName;
			break;
		case PHONENUMBER:
			value = this->PhoneNumber;
			break;
		case DARKESTSECRET:
			value = this->DarkestSecret;
			break;
		case IDX:
			std::stringstream ss;
			ss << idx + 1;
			value = ss.str();
	}
	if (value.length() > 10)
		return (value.substr(0, 9) + ".");
	return value;
}
