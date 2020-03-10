#include "pch.h"
#include "CppUnitTest.h"
#include "../Personal_Project/line.h"
#include <vector>
#include <algorithm>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

bool CMP(const pair<double, double> pair1, const pair<double, double> pair2)
{
	return (pair1.first > pair2.first || (pair1.first == pair2.first && pair1.second > pair2.second));
}

int compute(vector<line> lines)
{
	vector<pair<double, double>> intersections;
	for (unsigned i = 0; i < lines.size(); i++)
	{
		for (unsigned j = i + 1; j < lines.size(); j++)
		{
			cout << lines[i].intersect(lines[j], intersections) << endl;
		}
	}
	sort(intersections.begin(), intersections.end(), CMP);
	intersections.erase(unique(intersections.begin(), intersections.end()), intersections.end());
	return intersections.size();
}

namespace UnitTest
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			vector<line> lines;
			line line1 = line(0, 0, 1, 1);
			lines.push_back(line1);
			Assert::AreEqual(compute(lines), 0);
		}
	};

	TEST_CLASS(UnitTest2)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			vector<line> lines;
			line line1 = line(0, 0, 1, 1);
			line line2 = line(0, 0, 1, -1);
			lines.push_back(line1);
			lines.push_back(line2);
			Assert::AreEqual(compute(lines), 1);
		}
	};

	TEST_CLASS(UnitTest3)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			vector<line> lines;
			line line1 = line(0, 0, 1, 0);
			line line2 = line(0, 0, 0, 1);
			lines.push_back(line1);
			lines.push_back(line2);
			Assert::AreEqual(compute(lines), 1);
		}
	};

	TEST_CLASS(UnitTest4)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			vector<line> lines;
			line line1 = line(0, 0, 1, 1);
			line line2 = line(0, 0, 1, 0);
			lines.push_back(line1);
			lines.push_back(line2);
			Assert::AreEqual(compute(lines), 1);
		}
	};

	TEST_CLASS(UnitTest5)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			vector<line> lines;
			line line1 = line(0, 0, 1, 0);
			line line2 = line(0, 1, 1, 1);
			line line3 = line(0, 2, 1, 2);
			lines.push_back(line1);
			lines.push_back(line2);
			lines.push_back(line3);
			Assert::AreEqual(compute(lines), 0);
		}
	};

	TEST_CLASS(UnitTest6)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			vector<line> lines;
			line line1 = line(0, 0, 1, 0);
			line line2 = line(0, 1, 1, 1);
			line line3 = line(0, 0, 1, 2);
			lines.push_back(line1);
			lines.push_back(line2);
			lines.push_back(line3);
			Assert::AreEqual(compute(lines), 2);
		}
	};

	TEST_CLASS(UnitTest7)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			vector<line> lines;
			line line1 = line(0, 0, 1, 1);
			line line2 = line(0, 0, 1, -1);
			line line3 = line(0, 0, 1, 2);
			lines.push_back(line1);
			lines.push_back(line2);
			lines.push_back(line3);
			Assert::AreEqual(compute(lines), 1);
		}
	};

	TEST_CLASS(UnitTest8)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			vector<line> lines;
			line line1 = line(0, 0, 1, 1);
			line line2 = line(1, 0, 0, 1);
			line line3 = line(1, 2, 2, 0);
			lines.push_back(line1);
			lines.push_back(line2);
			lines.push_back(line3);
			Assert::AreEqual(compute(lines), 3);
		}
	};

	TEST_CLASS(UnitTest9)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			vector<line> lines;
			line line1 = line(0, 0, 1, 0);
			line line2 = line(0, 1, 1, 1);
			line line3 = line(0, 2, 1, 2);
			line line4 = line(0, -1, 1, 0);
			lines.push_back(line1);
			lines.push_back(line2);
			lines.push_back(line3);
			lines.push_back(line4);
			Assert::AreEqual(compute(lines), 3);
		}
	};

	TEST_CLASS(UnitTest10)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			vector<line> lines;
			line line1 = line(0, 0, 1, 1);
			line line2 = line(1, 0, 0, 1);
			line line3 = line(1, 2, 2, 0);
			line line4 = line(0, -1, 2, 0);
			lines.push_back(line1);
			lines.push_back(line2);
			lines.push_back(line3);
			lines.push_back(line4);
			Assert::AreEqual(compute(lines), 6);
		}
	};

}
