#include "Point.hpp"

/*----------------------CANONIC-----------------------*/
Point::Point(void) : _y(0), _x(0) {}
Point::Point(float const y, float const x) :_y(y), _x(x) {}
Point::Point(Point const & copie) : _y(copie.getY()), _x(copie.getX()){}
Point & Point::operator=(Point const &) {return *this;}
Point::~Point() {}

/*---------------GETTERS AND SETTERS---------------------*/
const Fixed&	Point::getY(void) const {return this->_y;}
const Fixed&	Point::getX(void) const {return this->_x;}



