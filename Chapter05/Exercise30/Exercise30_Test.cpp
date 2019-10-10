//Chapter 5 : Exercise 30

#include "pch.h"
#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string TestCase() {
	std::ostringstream out;
	int a[]{ 10, 20, 30, 40, 50 };
	int* p;
	for (p = a; p < a + sizeof(a) / sizeof(a[0]); ++p)
	{
		out << *p << " ";
	}
	return out.str();
}

TEST(Chapter5, Exercise30) {

	EXPECT_EQ("10 20 30 40 50 ", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
