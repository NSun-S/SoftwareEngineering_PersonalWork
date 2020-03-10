// Personal_Project.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include "line.h"
#include "circle.h"
#include <vector>
#include <fstream>
#include <string>
#include <ios>
#include <algorithm>
using namespace std;

bool cmp(const pair<double, double> pair1, const pair<double, double> pair2)
{
	return (pair1.first > pair2.first || (pair1.first == pair2.first && pair1.second > pair2.second));
}

bool myequal(const pair<double, double> pair1, const pair<double, double> pair2)
{
	return (fabs(pair1.first - pair2.first)<1e-10 && fabs(pair1.second - pair2.second) <1e-10);
}


int main()
{
	string input = "input.txt";
	string output = "output.txt";
	fstream inputfile(input);
	int n;
	inputfile >> n;
	vector<line> lines;
	vector<circle>circles;
	//set<pair<double, double>> intersections;
	vector<pair<double, double>> intersections;
	for (int i = 0; i < n; i++)
	{
		char type;
		inputfile >> type;
		if (type == 'L')
		{
			double x1, x2, y1, y2;
			inputfile >> x1 >> y1 >> x2 >> y2;
			lines.push_back(line(x1, y1, x2, y2));
		}
		else if (type == 'C')
		{
			double c1, c2, r;
			inputfile >> c1 >> c2 >> r;
			circles.push_back(circle(c1, c2, r));
		}
	}
	for (unsigned i = 0; i < lines.size(); i++)
	{
		for (unsigned j = i + 1; j < lines.size(); j++)
		{
			lines[i].intersect(lines[j], intersections);
		}
	}
	for (unsigned i = 0; i < circles.size(); i++)
	{
		for (unsigned j = i + 1; j < circles.size(); j++)
		{
			circles[i].intersectCircle(circles[j], intersections);
		}
		for (unsigned j = 0; j < lines.size(); j++)
		{
			circles[i].intersectLine(lines[j], intersections);
		}
	}
	sort(intersections.begin(), intersections.end(), cmp);
	//auto iter = unique(intersections.begin(), intersections.end());
	//intersections.erase(iter, intersections.end());
	//cout << intersections.size() << endl;
	int count = 1;
	for (unsigned i = 1; i < intersections.size(); i++)
	{
		if (!myequal(intersections[i - 1], intersections[i]))
		{
			count += 1;
		}
	}
	fstream outputFile(output, ios::out);
	//outputFile << intersections.size();
	outputFile << count;
	
	//for (auto iter = intersections.begin(); iter != intersections.end(); iter++)
	//{
	//	cout << iter->first << ' ' << iter->second << endl;
	//}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
