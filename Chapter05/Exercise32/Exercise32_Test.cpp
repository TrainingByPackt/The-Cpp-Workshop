//Chapter 5 : Exercise 32

#include "pch.h"
#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string TestCase() {
	std::ostringstream out;
	int i = 10;
	int& ir = i;
	i = i + 10;
	ir = ir * 10;
	out << "i = " << i << endl;
	int* ip = &ir;
	*ip = 33;
	out << "i = " << i << ", *ip = " << *ip << ", ir = " << ir << endl;

	return out.str();
}

TEST(Chapter5, Exercise32) {

	EXPECT_EQ("i = 200\ni = 33, *ip = 33, ir = 33\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}