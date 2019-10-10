//Chapter 4 : Exercise 23

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::string TestCase() {
	std::ostringstream out;
	int myInt = 5;

	out << ++myInt << std::endl;
	out << myInt << std::endl;

	myInt = 5;

	out << myInt++ << std::endl;
	out << myInt << std::endl;

	return out.str();
}

TEST(Chapter4, Exercise23) {
	EXPECT_EQ("6\n6\n5\n6\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}