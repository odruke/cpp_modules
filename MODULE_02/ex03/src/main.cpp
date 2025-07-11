#include "Point.hpp"
#include <iomanip>

bool bsp( Point const a, Point const b, Point const c, Point const point);

void print_triangle(const Point& a, const Point& b, const Point& c, const Point& p)
{
	int h = a.getY().toInt();
	int	w;

	while (h > 0){
		std::cout << std::setw(w)
	}

}

int	main()
{
	std::cout << "\033[2J\033[1;1H";

	Point const a(1.0f, 1.0f);
	Point const b(6.0f, 4.0f);
	Point const c(1.0f, 7.0f);
	// const Point point(5.0f, 7.0f);//outside
	Point const point(2.0f, 4.0f);//inside


	if (!DEBUG){
		print_triangle(a,b,c,point);
		return 0;
	}
	if (bsp(a ,b ,c, point))
		std::cout << "point is inside the triangle" << std::endl;
	else
		std::cout << "point is outside the triangle" << std::endl;
	return 0;
}
