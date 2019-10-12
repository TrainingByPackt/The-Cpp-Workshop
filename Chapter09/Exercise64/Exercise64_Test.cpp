//Chapter 9 : Exercise 64

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
#include <cmath>
using namespace std;

std::ostringstream out;
class Position
{
public:
	Position(float x, float y) : m_x(x), m_y(y) {}

	float distance(float x, float y)
	{
		float xDiff = x - m_x;
		float yDiff = y - m_y;

		return std::sqrt(((xDiff * xDiff) + (yDiff * yDiff)));
	}
	float getX() { return m_x; }
	float getY() { return m_y; }

	void setX(float x) { m_x = x; }
	void setY(float y) { m_y = y; }

private:

	float m_x;
	float m_y;
};

std::string TestCase() {
	float maxDistance = 500.0f;

	Position pos(10.0f, 20.0f);
	Position pos2(100.0f, 200.0f);

	bool validDistance = true;
	int numberOfTimesMoved = 0;

	while (validDistance)
	{
		float distance = pos.distance(pos2.getX(), pos2.getY());

		if (distance > maxDistance)
		{
			validDistance = false;
			break;
		}
		// get direction
		float xDirection = pos2.getX() - pos.getX();
		float yDirection = pos2.getY() - pos.getY();

		// normalize
		float normalizedX = xDirection / distance;
		float normalizedY = yDirection / distance;

		pos.setX(pos.getX() - normalizedX);
		pos.setY(pos.getY() - normalizedY);

		numberOfTimesMoved++;
	}

	out << "Too far apart." << " Moved " << numberOfTimesMoved << " times";

	return out.str();
}

TEST(Chapter9, Exercise64) {

	EXPECT_EQ("Too far apart. Moved 299 times", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
