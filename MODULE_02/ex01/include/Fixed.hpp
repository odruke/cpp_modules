#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					_value;
	static const int	_nbBits = 8;
public:
	Fixed();
	Fixed(Fixed const & copie);
	Fixed(const int);
	Fixed(const float);
	Fixed &	 operator=(Fixed const & add);
	~Fixed();


	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif
