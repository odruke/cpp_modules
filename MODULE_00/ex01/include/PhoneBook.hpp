

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

class PhoneBook
{
private:

	Contact	contacts[8];
	int		n_contacts;
	bool	FullMemory;

public:
	PhoneBook();
	~PhoneBook();
	void	AddContact(void);
	void	DisplayContacts(void);
	void	SearchContact(void);
	bool	FullContacts(void);
};

#endif
