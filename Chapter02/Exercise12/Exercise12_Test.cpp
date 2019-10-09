//Chapter 2 : Exercise 12

#include "pch.h"
#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string Loop(int multiple, int count) {
	std::ostringstream out;
	int numbersPrinted = 0;

	for (int i = 1; i <= 100; ++i)
	{
		if (numbersPrinted == count)
		{
			break;
		}

		if (i % multiple != 0)
		{
			continue;
		}
		out << i << "\n";
		++numbersPrinted;
	}
	return out.str();
}

TEST(Chapter2, Exercise12) {

	EXPECT_EQ("4\n8\n12\n16\n20\n24\n28\n32\n36\n40\n", Loop(4, 10));
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}