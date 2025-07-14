#include "Point.hpp"
#include <iomanip>

bool bsp( Point const a, Point const b, Point const c, Point const point);

void print_triangle(const Point& a, const Point& b, const Point& c, const Point& p)
{
    int ax = a.getX().toInt(), ay = a.getY().toInt();
    int bx = b.getX().toInt(), by = b.getY().toInt();
    int cx = c.getX().toInt(), cy = c.getY().toInt();
    int px = p.getX().toInt(), py = p.getY().toInt();

    int max_x = ax;
    if (bx > max_x) max_x = bx;
    if (cx > max_x) max_x = cx;
    if (px > max_x) max_x = px;
    int max_y = ay;
    if (by > max_y) max_y = by;
    if (cy > max_y) max_y = cy;
    if (py > max_y) max_y = py;

    for (int y = max_y; y >= 0; --y) {
        for (int x = 0; x <= max_x; ++x) {
            if (y == ay && x == ax)
                std::cout << 'A';
            else if (y == by && x == bx)
                std::cout << 'B';
            else if (y == cy && x == cx)
                std::cout << 'C';
            else if (y == py && x == px)
                std::cout << 'P';
            else
                std::cout << ' ';
        }
        std::cout << std::endl;
    }
}

int	main()
{
	std::cout << "\033[2J\033[1;1H";

	Point const a(2.25f, 1.59f);
	Point const b(6.74f, 4.55f);
	Point const c(1.42f, 7.98f);
	const Point point(5.0f, 4.0f);//outside
	// Point const point(2.0f, 4.0f);//inside


	if (DEBUG)
		print_triangle(a,b,c,point);
	if (bsp(a ,b ,c, point))
		std::cout << "point is inside the triangle" << std::endl;
	else
		std::cout << "point is outside the triangle" << std::endl;
	return 0;
}
