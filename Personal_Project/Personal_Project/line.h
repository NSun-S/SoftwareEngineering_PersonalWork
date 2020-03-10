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
	line(long long x1, long long y1, long long x2, long long y2);
	bool intersect(line line2, vector<pair<double, double>>& intersections);
	long long x1;
	long long y1;
	long long x2;
	long long y2;
};

