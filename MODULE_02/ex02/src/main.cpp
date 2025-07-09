#include "Fixed.hpp"

int	main()
{
	// Fixed		a;
	// Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;

	// std::cout << Fixed::max( a, b ) << std::endl;


	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << "<- valor de a sin iniciar" << std::endl;
	std::cout << ++a << "<- preincremento de a" << std::endl;
	std::cout << a << "<- valor de a actual" << std::endl;
	std::cout << a++ << "<- postincremento de a" << std::endl;
	std::cout << a << "<- valor de a" << std::endl;
	std::cout << b << "<- valor de b (5.05 * 2)" << std::endl;

	std::cout << Fixed::max( a, b ) << "<- cual es mas grande, a o b" << std::endl;
	return 0;
}
