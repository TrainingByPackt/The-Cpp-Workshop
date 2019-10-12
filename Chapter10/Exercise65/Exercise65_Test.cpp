//Chapter 10 : Exercise 65

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
class Shape
{
public:
	int area = 10;
	int GetArea() { return area; }
};

class Square : public Shape
{
};

class Circle : public Shape
{
};

class Triangle : public Shape
{
};

std::string TestCase() {
	Square mySquare;
	Circle myCircle;
	Triangle myTriangle;
	mySquare.area = 5;
	out << "Square Area: " << mySquare.GetArea() << std::endl;

	myCircle.area = 15;
	out << "Circle Area: " << myCircle.GetArea() << std::endl;

	out << "Triangle Area: " << myTriangle.GetArea() << std::endl;
	return out.str();
}

TEST(Chapter10, Exercise65) {

	EXPECT_EQ("Square Area: 5\nCircle Area: 15\nTriangle Area: 10\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
