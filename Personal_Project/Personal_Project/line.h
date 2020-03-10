#pragma once
#include <set>
#include <utility>

class line
{
public:
	line(int x1, int y1, int x2, int y2);
	bool intersect(int x3, int y3, int x4, int y4, set<pair<double, double>>& intersections);
private:
	int x1;
	int y1;
	int x2;
	int y2;

};

