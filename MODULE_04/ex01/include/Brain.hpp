#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <sstream>
# include <cstdlib>
# include "colors.hpp"
# define MAX_IDEAS 100

class Brain
{
private:
	std::string	_ideas[MAX_IDEAS];
public:
	Brain(void);
	Brain(Brain const& copy);
	virtual ~Brain();

	Brain&	operator=(Brain const& other);

	std::string const&	getIdea(int const& index) const;
	void	setIdea(std::string const& newIdea, int const& index);
};

#endif
