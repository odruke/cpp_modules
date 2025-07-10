#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Point	vectorAB(a.getY().toFloat() - b.getY().toFloat(), a.getX().toFloat() - b.getX().toFloat());
	Point	vectorBC(b.getY().toFloat() - c.getY().toFloat(), b.getX().toFloat() - c.getX().toFloat());
	Point	vectorCA(c.getY().toFloat() - a.getY().toFloat(), c.getX().toFloat() - a.getX().toFloat());

	Point	vectorAP(a.getY().toFloat() - point.getY().toFloat(), a.getX().toFloat() - point.getX().toFloat());
	Point	vectorBP(b.getY().toFloat() - point.getY().toFloat(), b.getX().toFloat() - point.getX().toFloat());
	Point	vectorCP(c.getY().toFloat() - point.getY().toFloat(), c.getX().toFloat() - point.getX().toFloat());

	Fixed ABAP, BCBP, CACP;
	ABAP = (vectorAB.getY().toFloat() * vectorAP.getX().toFloat()) - (vectorAB.getX().toFloat() * vectorAP.getY().toFloat());
	BCBP = (vectorBC.getY().toFloat() * vectorBP.getX().toFloat()) - (vectorBC.getX().toFloat() * vectorBP.getY().toFloat());
	CACP = (vectorCA.getY().toFloat() * vectorCP.getX().toFloat()) - (vectorCA.getX().toFloat() * vectorCP.getY().toFloat());

	if (ABAP.toFloat() >= 0 || BCBP.toFloat() >= 0 || CACP.toFloat() >= 0)
		return false;
	return true;
}
