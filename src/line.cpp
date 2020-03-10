#include "line.h"

line::line(double x1, double y1, double x2, double y2)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}


//bool line::intersect(line line2, set<pair<double, double>>& intersections)
bool line::intersect(line line2, vector<pair<double, double>>& intersections)
{
	double x3 = line2.x1;
	double x4 = line2.x2;
	double y3 = line2.y1;
	double y4 = line2.y2;
	double Determinant = (y1 - y2) * (x3 - x4) - (y3 - y4) * (x1 - x2);
	if (fabs(Determinant) < 1e-6) return false;
	double intersect_x = (-(x1 - x2) * (y3 * x4 - x3 * y4) + (x3 - x4) * (y1 * x2 - x1 * y2)) / Determinant;
	double intersect_y = (-(y1 - y2) * (y3 * x4 - x3 * y4) + (y3 - y4) * (y1 * x2 - x1 * y2)) / Determinant;
	//intersections.insert(make_pair(intersect_x, intersect_y));
	intersections.push_back(make_pair(intersect_x, intersect_y));
	return true;
}


