

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

typedef enum e_ContactMember
{
	FIRSTNAME,
	LASTNAME,
	NICKNAME,
	PHONENUMBER,
	DARKESTSECRET,
	IDX
}t_ContactMember;

class Contact
{

	public:
	Contact();
	Contact(int ide);
	~Contact();
	void		NewContact(int ide);
	void		PrintContact();
	std::string getField(e_ContactMember field) const;
	static int	getNbContacts();
	static void	setNbContacts(int newNb);

private:

	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string	_phoneNumber;
	std::string _darkestSecret;
	int			_idx;
	static int	_nbContacts;

};

#endif
