//Chapter 10: Exercise 66

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;

class Color
{
public:
	std::string color = "";
	std::string GetColor() { return color; }
};
class Shape
{
public:
	int area = 10;
	int GetArea() { return area; }
};

class Square : public Shape, public Color
{
};
class Circle : public Shape, public Color
{
};
class Triangle : public Shape, public Color
{
};

std::string TestCase() {
	Square mySquare;
	Circle myCircle;
	Triangle myTriangle;

	mySquare.area = 5;
	mySquare.color = "red";
	out << "Square Area: " << mySquare.GetArea() << std::endl;
	out << "Square Color: " << mySquare.GetColor() << std::endl;

	myCircle.area = 10;
	myCircle.color = "blue";
	out << "Circle Area: " << myCircle.GetArea() << std::endl;
	out << "Circle Area: " << myCircle.GetColor() << std::endl;

	myTriangle.area = 15;
	myTriangle.color = "green";
	out << "Triangle Area: " << myTriangle.GetArea() << std::endl;
	out << "Triangle Color: " << myTriangle.GetColor() << std::endl;

	return out.str();
}

TEST(Chapter10, Exercise66) {

	EXPECT_EQ("Square Area: 5\nSquare Color: red\nCircle Area: 10\nCircle Area: blue\nTriangle Area: 15\nTriangle Color: green\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}