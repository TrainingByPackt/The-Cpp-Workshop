//Chapter 6 : Exercise 37

#include "pch.h"
#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string Pointer(bool checkAddress) {
	std::ostringstream out;
	int* pint = nullptr;

	pint = new int{ 33333 };
	out << "*pint = " << *pint << endl;
	delete pint;

	return out.str();
}

TEST(Chapter6, Exercise37) {

	EXPECT_EQ("*pint = 33333\n", Pointer(false));
	EXPECT_EQ("*pint = 33333\n", Pointer(true));
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}