#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					_bitValue;
	static const int	_fractBits;
public:
	Fixed();
	Fixed(Fixed const & copie);
	Fixed(const int value);
	Fixed(const float value);
	Fixed &	 operator=(Fixed const & add);
	~Fixed();


	int getRawBits( void ) const;
	void setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream & operator<<(std::ostream& o, Fixed const & value );

#endif
