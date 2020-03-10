#include "line.h"

line::line(int x1, int y1, int x2, int y2)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}


bool line::intersect(int x3, int y3, int x4, int y4, set<pair<double, double>>& intersections)
{
	double Determinant = (y1 - y2) * (x3 - x4) - (y3 - y4) * (x1 - x2);
	if (Determinant < 1e-6) return false;
	double intersect_x = ((x1 - x2) * (y3 * x4 - x3 * y4) - (x3 - x4) * (y1 * x2 - x1 * y2)) / Determinant;
	double intersect_y = ((y1 - y2) * (y3 * x4 - x3 * y4) - (y3 - y4) * (y1 * x2 - x1 * y2)) / Determinant;
	intersections.insert(make_pair(intersect_x, intersect_y));
	return false;
}


