#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <sstream>
# include "colors.hpp"

class Brain
{
private:
	std::string	_ideas[100];
public:
	Brain(void);
	Brain(Brain const& copy);
	virtual ~Brain();

	Brain&	operator=(Brain const& other);
};

#endif
