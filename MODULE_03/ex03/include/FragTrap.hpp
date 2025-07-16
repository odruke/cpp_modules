#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(std::string const& name);
	FragTrap(FragTrap const& add);
	FragTrap&	operator=(FragTrap const& add);
	~FragTrap();

	void	attack(const std::string& target);
	void	highFivesGuys(void);
};

#endif
