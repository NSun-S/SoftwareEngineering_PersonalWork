#include "circle.h"

circle::circle(double c1, double c2, double r)
{
	this->c1 = c1;
	this->c2 = c2;
	this->r = r;
}

pair<double, double> circle::getFoot(line line1)
{
	vector<pair<double, double>> intersection;
	if (line1.x1 == line1.x2)
	{
		line line2 = line(c1, c2, c1+1, c2);
		line1.intersect(line2, intersection);
		//return *intersection.begin();
		return intersection[0];
	}
	else if (line1.y1 == line1.y2)
	{
		line line2 = line(c1, c2, c1, c2+1);
		line1.intersect(line2, intersection);
		//return *intersection.begin();
		return intersection[0];
	}
	else
	{
		double cof = -(line1.x2 - line1.x1) / (line1.y2 - line1.y1);
		line line2 = line(c1, c2, c1 + 1, c2 + cof);
		line1.intersect(line2, intersection);
		//return *intersection.begin();
		return intersection[0];
	}
}

double circle::getDistance(line line1)
{
	pair<double, double> foot = getFoot(line1);
	return sqrt(pow((foot.first - c1),2) + pow((foot.second - c2),2));
}

//int circle::intersectLine(line line1, set<pair<double, double>>& intersections)
int circle::intersectLine(line line1, vector<pair<double, double>>& intersections)
{
	double distance = getDistance(line1);
	//cout << distance << endl;
	if (distance > r)
	{
		//cout << "???" << endl;
		return 0;
	}
	pair<double, double> foot = getFoot(line1);
	if (distance == r)
	{
		//intersections.insert(foot);
		intersections.push_back(foot);
		return 1;
	}
	double length = sqrt(r*r - distance*distance);
	if (line1.x1 == line1.x2)
	{
		//intersections.insert(make_pair(foot.first, foot.second + length));
		intersections.push_back(make_pair(foot.first, foot.second + length));
		//intersections.insert(make_pair(foot.first, foot.second - length));
		intersections.push_back(make_pair(foot.first, foot.second - length));
	}
	else
	{
		double cof = (line1.y1 - line1.y2) / (line1.x1 - line1.x2);
		double x = 1 / sqrt(cof * cof + 1);
		double y = cof / sqrt(cof * cof + 1);
		//intersections.insert(make_pair(foot.first + x * length, foot.second + y * length));
		intersections.push_back(make_pair(foot.first + x * length, foot.second + y * length));
		//intersections.insert(make_pair(foot.first - x * length, foot.second - y * length));
		intersections.push_back(make_pair(foot.first - x * length, foot.second - y * length));
	}
	return 2;
}

//int circle::intersectCircle(circle circle2, set<pair<double, double>>& intersections)
int circle::intersectCircle(circle circle2, vector<pair<double, double>>& intersections)
{
	double distance = sqrt(circle2.r * circle2.r - r * r);
	if (distance > (r + circle2.r) || distance < fabs(r - circle2.r)) return 0;
	double right = circle2.r * circle2.r - r * r + c1 * c1 - circle2.c1 * circle2.c1 
		+ c2 * c2 - circle2.c2 * circle2.c2;
	if (circle2.c1 == c1)
	{
		double y = -right / (2 * circle2.c2 - 2 * c2);
		line line1 = line(1, y, -1, y);
		return intersectLine(line1, intersections);
	}
	else if(circle2.c2 == c2)
	{
		double x = -right / (2 * circle2.c1 - 2 * c1);
		line line1 = line(x, 1, x, -1);
		return intersectLine(line1, intersections);
	}
	else
	{
		//cout << "emmm\n";
		line line1 = line(0, -right/(2 * circle2.c2 - 2 * c2), -right / (2 * circle2.c1 - 2 * c1), 0);
		//cout << right / (2 * circle2.c2 - 2 * c2) << ' '<<right / (2 * circle2.c1 - 2 * c1) << endl;
		return intersectLine(line1, intersections);
	}
}



