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
