// Personal_Project.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "line.h"
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

int main()
{
	string input = "3000.txt";
	string output = "output.txt";
	fstream inputfile(input);
	int n;
	inputfile >> n;
	vector<line> lines;
	//set<pair<double, double>> intersections;
	vector<pair<double, double>> intersections;
	for (int i = 0; i < n; i++)
	{
		char type;
		inputfile >> type;
		if (type == 'L')
		{
			int x1, x2, y1, y2;
			inputfile >> x1 >> y1 >> x2 >> y2;
			lines.push_back(line(x1, y1, x2, y2));
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			lines[i].intersect(lines[j], intersections);
		}
	}
	sort(intersections.begin(), intersections.end(), cmp);
	intersections.erase(unique(intersections.begin(), intersections.end()), intersections.end());
	//cout << intersections.size() << endl;
	fstream outputFile(output, ios::out);
	outputFile << intersections.size();
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
