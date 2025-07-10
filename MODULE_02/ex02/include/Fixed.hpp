#ifndef FIXED_HPP
# define FIXED_HPP
#ifndef DEBUG
# define DEBUG 0
#endif

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
	Fixed &	operator=(Fixed const & add);
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;
	static Fixed	min(Fixed & a, Fixed & b);
	static Fixed	min(Fixed const & a, Fixed const & b);
	static Fixed	max(Fixed & a, Fixed & b);
	static Fixed	max(Fixed const & a, Fixed const & b);


	bool	operator==(Fixed const & compare) const;
	bool	operator!=(Fixed const & compare) const;
	bool	operator>(Fixed const & compare) const;
	bool	operator<(Fixed const & compare) const;
	bool	operator<=(Fixed const & compare) const;
	bool	operator>=(Fixed const & compare) const;

	Fixed	operator+(Fixed const & value);
	Fixed	operator-(Fixed const & value);
	Fixed	operator*(Fixed const & value);
	Fixed	operator/(Fixed const & value);

	Fixed	operator++();
	Fixed	operator--();
	Fixed	operator++(int);
	Fixed	operator--(int);



};

std::ostream & operator<<(std::ostream& o, Fixed const & value );

#endif
