//Chapter 2 : Exercise 11

#include "pch.h"
#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string WhileLoop() {
	std::ostringstream out;

	int count = 0;

	while (count < 5)
	{
		++count;
		out << "\n" << count;
	}
	return out.str();
}

TEST(Chapter2, Exercise11) {

	EXPECT_EQ("\n1\n2\n3\n4\n5", WhileLoop());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}