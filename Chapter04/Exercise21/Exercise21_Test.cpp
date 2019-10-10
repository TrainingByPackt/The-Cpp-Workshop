//Chapter 4 : Exercise 21

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::string TestCase(int numberToCheck) {
	std::ostringstream out;
	if (numberToCheck <= 1)
	{
		out << numberToCheck << " is not prime.";
		return out.str();
	}
	else if (numberToCheck == 2)
	{
		out << numberToCheck << " is prime.";
		return out.str();
	}
	for (int i = 2; i < numberToCheck; ++i)
	{
		if (numberToCheck % i == 0)
		{
			out << numberToCheck << " is not prime.";
			return out.str();
		}
	}
	out << numberToCheck << " is prime.";

	return out.str();
}

TEST(Chapter4, Exercise21) {
	EXPECT_EQ("10 is not prime.", TestCase(10));
	EXPECT_EQ("1 is not prime.", TestCase(1));
	EXPECT_EQ("2 is prime.", TestCase(2));
	EXPECT_EQ("11 is prime.", TestCase(11));
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}