#pragma once
#include <utility>
#include "line.h"
#include <math.h>
using namespace std;
class circle
{
public:
	circle(double c1, double c2, double r);
	pair<double, double>getFoot(line line1);
	double getDistance(line line1);
	int intersectLine(line line1, vector<pair<double, double>>& intersections);
	int intersectCircle(circle circle2, vector<pair<double, double>>& intersections);
	double c1, c2, r;
};
	//int intersectLine(line line1, set<pair<double, double>>& intersections);
	//int intersectCircle(circle circle2, set<pair<double, double>>& intersections);