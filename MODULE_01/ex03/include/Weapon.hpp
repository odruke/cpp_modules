
#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
	std::string _type;
public:
	Weapon();
	Weapon(std::string newType);
	~Weapon();

	std::string	getType()const;
	void		setType(std::string newType);
};

#endif
