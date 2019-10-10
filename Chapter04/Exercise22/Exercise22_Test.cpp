//Chapter 4 : Exercise 22

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::string TestCase(int time) {
	std::ostringstream out;
	if (time < 0000 || time > 2400)
	{
		out << "Invalid time.";
		return out.str();
	}
	if (time == 0000)
	{
		out << "It's currently midnight.";
	}
	else if (time == 1200)
	{
		out << "It's currently noon.";
	}
	else if (time >= 0600 && time < 1200)
	{
		out << "It's currently morning.";
	}
	else if (time > 1200 && time <= 1700)
	{
		out << "It's currently afternoon.";
	}
	else if (time > 1700 && time <= 2000)
	{
		out << "It's currently evening.";
	}
	else if (time > 2000 || time < 0600)
	{
		out << "It's currently night.";
	}

	return out.str();
}

TEST(Chapter4, Exercise22) {
	EXPECT_EQ("Invalid time.", TestCase(-2000));
	EXPECT_EQ("Invalid time.", TestCase(3000));
	EXPECT_EQ("It's currently midnight.", TestCase(0000));
	EXPECT_EQ("It's currently noon.", TestCase(1200));
	EXPECT_EQ("It's currently morning.", TestCase(1000));
	EXPECT_EQ("It's currently afternoon.", TestCase(1500));
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}