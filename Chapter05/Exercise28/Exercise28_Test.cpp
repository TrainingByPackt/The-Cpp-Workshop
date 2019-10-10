//Chapter 5 : Exercise 28

#include "pch.h"
#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;

std::string TestCase() {
	int a[7]{ 1, 3, 5, 4, 2, 9, -1 };
	int* p = nullptr;

	p = &a[2];
	out << "*p = " << *p << ", a[2] = " << a[2] << endl;

	out << "p[3] = " << p[3] << ", a[5] = " << a[5] << endl;

	return out.str();
}

TEST(Chapter5, Exercise28) {

	EXPECT_EQ("*p = 5, a[2] = 5\np[3] = 9, a[5] = 9\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
