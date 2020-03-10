#pragma once
#include <set>
#include <utility>
#include <math.h>
#include <iostream>
using namespace std;
class line
{
public:
	line(int x1, int y1, int x2, int y2);
	bool intersect(line line2, set<pair<float, float>>& intersections);
	int x1;
	int y1;
	int x2;
	int y2;
};

