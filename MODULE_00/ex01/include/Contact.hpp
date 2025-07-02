

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
private:

	std::string FirstName;
	std::string LastName;
	std::string NickName;
	std::string	PhoneNumber;
	std::string DarkestSecret;
	int			idx;

	typedef std::string Contact::* FieldPtr;
public:
	Contact();
	Contact(int ide);
	~Contact();
	void		NewContact(int ide);
	void		PrintContact();
	std::string GetField(e_ContactMember field) const;
};

#endif
