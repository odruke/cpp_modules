#include "Fixed.hpp"


const int Fixed::_fractBits = 8;

Fixed::Fixed() : _bitValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & copie)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copie;
}
/*the bitwise operator will displace the bits 8 positions and setting
to 0 the ones left on the right*/
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_bitValue = value << this->_fractBits;
}

/*we multiply the float to 256 to desplace the coma 8 bits to right,
then we round with roundf and store*/
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_bitValue = roundf(value * (1 << this->_fractBits));
}

Fixed& Fixed::operator=(Fixed const & add)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_bitValue = add.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return this->_bitValue;
}

void	Fixed::setRawBits(int const raw)
{
	this->_bitValue = raw;
}
/*we reverse what we did to store it as raw bits, and we cast it to a float*/
float	Fixed::toFloat(void) const
{
	return ((float)this->_bitValue / (float)(1 << this->_fractBits));
}

/*we use the bitwise operator to pass the bits 8 positions, and actively
displacing the coma*/
int		Fixed::toInt(void) const
{
	return this->_bitValue >> this->_fractBits;
}

std::ostream & operator<<(std::ostream& o, Fixed const & value )
{
	o << value.toFloat();
	return o;
}
