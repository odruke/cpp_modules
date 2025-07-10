#include "Fixed.hpp"
#include <iomanip>

int	main()
{
	std::cout << "\033[2J\033[1;1H";
	if (!DEBUG){
		Fixed		a;
		Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;

		std::cout << Fixed::max( a, b ) << std::endl;

		return 0;
	}

	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed 		c(2.5f);
	Fixed		d(1);


	std::cout
		<< std::setfill('*') << std::setw(15) << std::left << "*"
		<< " PREINCREMENT " << std::setw(15) << std::left << "*" << "\n" << std::endl;

	std::cout
		<< std::setfill('-') << std::setw(13) << std::left
		<< a << "initialized a value\n" << std::endl;
	std::cout
		<< std::setw(13) << std::left
		<< ++a  << "preincrement of a" << std::endl;
	std::cout
		<< std::setw(13) << std::left
		<< a << "a value at this point" << std::endl;
	std::cout
		<< std::setw(13) << std::left
		<< a++ << "postincrement of a" << std::endl;
	std::cout
		<< std::setw(13) << std::left
		<< a << "a value at this point\n" << std::endl;


	std::cout
		<< std::setfill('*') << std::setw(15) << std::left << "*"
		<< " COMPARISON " << std::setw(15) << std::left << "*" << "\n" << std::endl;

	std::cout
		<< std::setfill('-') << std::setw(13) << std::left
		<< b << "value of b (5.05 * 2)" << std::endl;
	std::cout
		<< std::setw(13) << std::left
		<< Fixed::max( a, b ) << "wich one is bigger a->("
		<< a << ") or b->("<< b <<")\n" << std::endl;


	std::cout
		<< std::setfill('*') << std::setw(15) << std::left << "*"
		<< " DECREMENTATION " << std::setw(15) << std::left << "*" << "\n" << std::endl;

	std::cout
		<< std::setfill('-') << std::setw(13) << std::left
		<< a << "a value at this point" << std::endl;
	std::cout
		<< std::setw(13) << std::left
		<< --a  << "predecrement of a" << std::endl;
	std::cout
		<< std::setw(13) << std::left
		<< a << "a value at this point" << std::endl;
	std::cout
		<< std::setw(13) << std::left
		<< a-- << "postdecrement of a" << std::endl;
	std::cout
		<< std::setw(13) << std::left
		<< a << "a value at this point\n" << std::endl;


	std::cout
		<< std::setfill('*') << std::setw(15) << std::left << "*"
		<< " ARITMETICS " << std::setw(15) << std::left << "*" << "\n" << std::endl;

	std::cout
		<< std::setfill('-') << std::setw(13) << std::left
		<< c + d << "c + d (2.5 + 1)" << std::endl;
	std::cout
		<< std::setw(13) << std::left
		<< c - d << "c - d (2.5 - 1)" << std::endl;
	std::cout
		<< std::setw(13) << std::left
		<< d - c << "d - c (1 - 2.5)" << std::endl;
	std::cout
		<< std::setw(13) << std::left
		<< d + d + d + c << "d + d + d + d + c (1 + 1 + 1 + 2.5)" << std::endl;
	std::cout
		<< std::setw(13) << std::left
		<< d + c - d << "d + c - d (1 - 2.5 + 1)" << std::endl;
	std::cout
		<< std::setw(13) << std::left
		<< d + c - d << "d + c - d (1 - 2.5 + 1)" << std::endl;
		a = (d + c);
	std::cout
		<< std::setw(13) << std::left
		<< a << "a = d + c (1 + 2.5)" << std::endl;
	std::cout
		<< std::setw(13) << std::left
		<< d / c << "d / c (1 / 2.5)" << std::endl;
	std::cout
		<< std::setw(13) << std::left
		<< a * c << "a * c(3.5 * 2.5)\n" << std::endl;
	/* division by 0 will crash the program as specified in the subject*/
	// Fixed	e;
	// std::cout
	// 	<< std::setw(13) << std::left
	// 	<< a / e << "a / e (3.5 / 0)" << std::endl;

	// Additional tests
	std::cout
		<< std::setfill('*') << std::setw(15) << std::left << "*"
		<< " EXTRA TESTS " << std::setw(15) << std::left << "*" << "\n" << std::endl;

	Fixed zero(0);
	Fixed neg(-2.5f);
	Fixed big(1000.25f);

	// Arithmetic with zero
	std::cout << std::setfill('-') << std::setw(13) << std::left << zero + c << "zero + c (0 + 2.5)" << std::endl;
	std::cout << std::setw(13) << std::left << zero - c << "zero - c (0 - 2.5)" << std::endl;
	std::cout << std::setw(13) << std::left << zero * c << "zero * c (0 * 2.5)" << std::endl;
	// Division by zero (should be handled gracefully if implemented)
	// std::cout << std::setw(13) << std::left << c / zero << "c / zero (2.5 / 0)" << std::endl;

	// Arithmetic with negatives
	std::cout << std::setw(13) << std::left << c + neg << "c + neg (2.5 + -2.5)" << std::endl;
	std::cout << std::setw(13) << std::left << c - neg << "c - neg (2.5 - -2.5)" << std::endl;
	std::cout << std::setw(13) << std::left << neg * d << "neg * d (-2.5 * 1)" << std::endl;
	std::cout << std::setw(13) << std::left << neg / d << "neg / d (-2.5 / 1)" << std::endl;

	// Arithmetic with big numbers
	std::cout << std::setw(13) << std::left << big + c << "big + c (1000.25 + 2.5)" << std::endl;
	std::cout << std::setw(13) << std::left << big - c << "big - c (1000.25 - 2.5)" << std::endl;
	std::cout << std::setw(13) << std::left << big * d << "big * d (1000.25 * 1)" << std::endl;
	std::cout << std::setw(13) << std::left << big / d << "big / d (1000.25 / 1)" << std::endl;

	// Comparison tests
	std::cout << std::setfill('-') << std::setw(13) << std::left << (c == d) << "c == d (2.5 == 1)" << std::endl;
	std::cout << std::setw(13) << std::left << (c != d) << "c != d (2.5 != 1)" << std::endl;
	std::cout << std::setw(13) << std::left << (c > d) << "c > d (2.5 > 1)" << std::endl;
	std::cout << std::setw(13) << std::left << (c < d) << "c < d (2.5 < 1)" << std::endl;
	std::cout << std::setw(13) << std::left << (c >= d) << "c >= d (2.5 >= 1)" << std::endl;
	std::cout << std::setw(13) << std::left << (c <= d) << "c <= d (2.5 <= 1)" << std::endl;
	std::cout << std::setw(13) << std::left << (c == c) << "c == c (2.5 == 2.5)" << std::endl;
	std::cout << std::setw(13) << std::left << (neg < zero) << "neg < zero (-2.5 < 0)" << std::endl;
	std::cout << std::setw(13) << std::left << (neg > zero) << "neg > zero (-2.5 > 0)" << std::endl;

	// Increment/decrement edge cases
	std::cout << std::setw(13) << std::left << ++neg << "preincrement neg (-2.5)" << std::endl;
	std::cout << std::setw(13) << std::left << neg++ << "postincrement neg" << std::endl;
	std::cout << std::setw(13) << std::left << --neg << "predecrement neg" << std::endl;
	std::cout << std::setw(13) << std::left << neg-- << "postdecrement neg" << std::endl;
	std::cout << std::setw(13) << std::left << neg << "neg value at this point" << std::endl;
	return 0;
}
