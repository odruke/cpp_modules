#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Point	vectorAB(b.getY().toFloat() - a.getY().toFloat(), b.getX().toFloat() - a.getX().toFloat());
	Point	vectorBC(c.getY().toFloat() - b.getY().toFloat(), c.getX().toFloat() - b.getX().toFloat());
	Point	vectorCA(a.getY().toFloat() - c.getY().toFloat(), a.getX().toFloat() - c.getX().toFloat());

	Point	vectorAP(point.getY().toFloat() - a.getY().toFloat(), point.getX().toFloat() - a.getX().toFloat());
	Point	vectorBP(point.getY().toFloat() - b.getY().toFloat(), point.getX().toFloat() - b.getX().toFloat());
	Point	vectorCP(point.getY().toFloat() - c.getY().toFloat(), point.getX().toFloat() - c.getX().toFloat());

	Fixed	ABAP, BCBP, CACP;
	ABAP = (vectorAB.getY().toFloat() * vectorAP.getX().toFloat()) - (vectorAB.getX().toFloat() * vectorAP.getY().toFloat());
	BCBP = (vectorBC.getY().toFloat() * vectorBP.getX().toFloat()) - (vectorBC.getX().toFloat() * vectorBP.getY().toFloat());
	CACP = (vectorCA.getY().toFloat() * vectorCP.getX().toFloat()) - (vectorCA.getX().toFloat() * vectorCP.getY().toFloat());

	if (ABAP.toFloat() < 0 && BCBP.toFloat() < 0 && CACP.toFloat() < 0)
		return true;
	else if (ABAP.toFloat() > 0 && BCBP.toFloat() > 0 && CACP.toFloat() > 0)
		return true;
	return false;
}
