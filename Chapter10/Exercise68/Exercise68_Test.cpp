//Chapter 10 : Exercise 68

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;

class Shape
{
public:
	virtual int CalculateArea() = 0;

protected:
	int area = 0;
};
class Square : public Shape
{
public:
	int height = 0;

	int CalculateArea() override
	{
		area = height * height;
		return area;
	}
};
class Circle : public Shape
{
public:
	int radius = 0;

	int CalculateArea() override
	{
		area = 3.14 * (radius * radius);
		return area;
	}
};

std::string TestCase() {
	Square square;
	square.height = 10;
	out << "Square Area: " << square.CalculateArea() << std::endl;

	Circle circle;
	circle.radius = 10;
	out << "Circle Area: " << circle.CalculateArea() << std::endl;

	return out.str();
}

TEST(Chapter10, Exercise68) {

	EXPECT_EQ("Square Area: 100\nCircle Area: 314\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}