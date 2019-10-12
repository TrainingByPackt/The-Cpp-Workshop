//Chapter 12 : Exercise 75

#include "pch.h"
#include <iostream>
#include <memory>
#include <typeinfo>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;

std::string TestCase() {
	vector<int> vec = { 1,2,3,4,5,6,7,8,9,10 };

	for (auto v : vec)
	{
		out << v << " ";
	}

	out << vec[3];

	return out.str();
}

TEST(Chapter12, Exercise75) {

	EXPECT_EQ("1 2 3 4 5 6 7 8 9 10 4", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}