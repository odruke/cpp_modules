#include "Fixed.hpp"


const int Fixed::_fractBits = 8;

/*----------------------CANONIC-----------------------*/

Fixed::Fixed() : _bitValue(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & copie) : _bitValue(copie.getRawBits())
{
	// std::cout << "Copy constructor called" << std::endl;
}
/*the bitwise operator will displace the bits 8 positions and setting
to 0 the ones left on the right*/
Fixed::Fixed(const int value)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_bitValue = value << this->_fractBits;
}

/*we multiply the float to 256 to desplace the coma 8 bits to right,
then we round with roundf and store*/
Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_bitValue = roundf(value * (1 << this->_fractBits));
}
Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=(Fixed const & add)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_bitValue = add.getRawBits();
	return *this;
}

/*---------------GETTERS AND SETTERS---------------------*/

int	Fixed::getRawBits(void) const
{
	return this->_bitValue;
}

void	Fixed::setRawBits(int const raw)
{
	this->_bitValue = raw;
}

/*-----------------TYPE CONVERSION FUNCTIONS----------------------*/
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

/*------------------COMPARISON OPERATORS-----------------------*/

bool	Fixed::operator==(Fixed const & compare) const
{
	if (this->_bitValue == compare.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator!=(Fixed const & compare) const
{
	if (this->_bitValue == compare.getRawBits())
		return false;
	return true;
}

bool	Fixed::operator>(Fixed const & compare) const
{
	if (this->_bitValue > compare.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<(Fixed const & compare) const
{
	if (this->_bitValue < compare.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator>=(Fixed const & compare) const
{
	if (this->_bitValue >= compare.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<=(Fixed const & compare) const
{
	if (this->_bitValue <= compare.getRawBits())
		return true;
	return false;
}

/*------------------ARITMETIC OPERATORS------------------------*/

Fixed	Fixed::operator+(Fixed const & value)
{
	Fixed res;
	res.setRawBits(this->_bitValue + value.getRawBits());
	return res;
}

Fixed	Fixed::operator-(Fixed const & value)
{
	Fixed res;
	res.setRawBits(this->_bitValue - value.getRawBits());
	return res;
}

/*the multiplication could easely overflow the int value
so we cast to long long. then we have to set back to right the coma
as we doubled the bits by multipling*/
Fixed	Fixed::operator*(Fixed const & value)
{
	Fixed	res;
	long long int tmp = (long long int )this->_bitValue * value.getRawBits();
	res.setRawBits((int)(tmp >> this->_fractBits));
	return res;
}

/*in the division, we will lose the fractional bits, so we cast to long long
to have more bits, and displace to left the coma so we don't lose the fractional part.*/
Fixed	Fixed::operator/(Fixed const & value)
{
	Fixed	res;
	long long int tmp = ((long long int )this->_bitValue << this->_fractBits);
	res.setRawBits((int)(tmp / value.getRawBits()));
 	return res;
}
/*----------------INCREMENTATION OPERATORS---------------------*/

/*pre*/
Fixed	Fixed::operator++()
{
	this->_bitValue++;
	return *this;
}

Fixed	Fixed::operator--()
{
	this->_bitValue--;
	return *this;
}

/*post*/
Fixed	Fixed::operator++(int)
{
	Fixed	old = *this;

	this->_bitValue++;
	return old;
}

Fixed	Fixed::operator--(int)
{
	Fixed	old = *this;

	this->_bitValue--;
	return old;
}



/*----------------------MIN MAX FUNCTIONS----------------------*/

Fixed	Fixed::min(Fixed & a, Fixed & b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed	Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed	Fixed::max(Fixed & a, Fixed & b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

Fixed	Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

/*-------------------NO MEMBER FUNCTIONS----------------------*/

std::ostream & operator<<(std::ostream& o, Fixed const & value )
{
	o << value.toFloat();
	return o;
}
