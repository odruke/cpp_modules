#include "Harl.hpp"

Harl::Harl()
{
	return;
}

Harl::~Harl()
{
	return;
}

void	Harl::_debug(void)
{
	std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::_info(void)
{
	std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::_warning(void)
{
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free. I’ve been coming foryears, whereas you started working here just last month." << std::endl;
}

void	Harl::_error(void)
{
	std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	void	(Harl::*funtionPTR[])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i;
	for (i = 0; i < 4; i++)
		if (!levels[i].compare(level))
			break;

	/*in this switch statement we don't break
	after the case, for that we use [[fallthrough]] instead
	of break, but is a c++17 feature and therefore not allowed.
	The compilator in c++98 will recognize the comment //fall trough
	and work the same way*/
	switch (i)
	{
	case 0:
		(this->*funtionPTR[0])();
		//fall through
	case 1:
		(this->*funtionPTR[1])();
		//fall through
	case 2:
		(this->*funtionPTR[2])();
		//fall through
	case 3:
		(this->*funtionPTR[3])();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}
