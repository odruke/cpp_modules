#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# define RESET		"\033[0m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

# include <iostream>

class Animal
{
protected:
	std::string _type;
public:
	Animal(void);
	Animal(std::string const& type);
	Animal(Animal const& copy);
	~Animal();
	Animal	operator=(Animal const& copy);
};

#endif
