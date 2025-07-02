

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

class PhoneBook
{
	public:

	PhoneBook();
	~PhoneBook();
	void	AddContact(void);
	void	DisplayContacts(void);
	void	SearchContact(void);
	bool	FullContacts(void);

private:

	Contact	contacts[8];
	bool	FullMemory;

};

#endif
