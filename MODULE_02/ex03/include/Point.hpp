#ifndef POINT_HPP
# define POINT_HPP
#include "Fixed.hpp"

class Point
{
private:

	const Fixed	_y;
	const Fixed	_x;

public:
	Point( void );
	Point(float const y, float const x);
	Point(Point const & copie);
	Point & operator=(Point const &);
	~Point( void );

	Fixed	getY( void ) const;
	Fixed	getX( void ) const;
};

#endif
