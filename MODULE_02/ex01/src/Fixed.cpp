#include "Fixed.hpp"


Fixed::Fixed() : _bitValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & copie)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copie;
}

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
	std::cout << "getRawBits member function called" << std::endl;
	return this->_bitValue;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_bitValue = raw;
}

float	Fixed::toFloat(void) const
{
	
}
