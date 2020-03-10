#pragma once
#include <set>
#include <utility>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;
class line
{
public:
	line(double x1, double y1, double x2, double y2);
	bool intersect(line line2, vector<pair<double, double>>& intersections);
	double x1;
	double y1;
	double x2;
	double y2;
};

//bool intersect(line line2, set<pair<double, double>>& intersections);