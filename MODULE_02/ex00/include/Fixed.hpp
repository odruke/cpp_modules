#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class Fixed
{
private:
	int					_bitValue;
	static const int	_fractBits = 8;
public:
	Fixed();
	Fixed(Fixed const & copie);
	Fixed &	 operator=(Fixed const & add);
	~Fixed();


	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif
