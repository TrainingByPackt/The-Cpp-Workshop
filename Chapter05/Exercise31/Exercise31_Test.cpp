//Chapter 5 : Exercise 31

#include "pch.h"
#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string TestCase() {
	std::ostringstream out;
	char* alphabet[26]
	{
	   "alpha",
	   "bravo",
	   "charlie",
	   "delta",
	   "echo",
	   "foxtrot"
	};
	for (char** p = alphabet; *p != nullptr; ++p)
	{
		out << *p << " ";
	}

	return out.str();
}

TEST(Chapter5, Exercise31) {

	EXPECT_EQ("alpha bravo charlie delta echo foxtrot ", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}