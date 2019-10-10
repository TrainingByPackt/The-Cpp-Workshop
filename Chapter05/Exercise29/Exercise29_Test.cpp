//Chapter 5 : Exercise 29 

#include "pch.h"
#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string TestCase() {
	std::ostringstream out;
	int numbers[5]{ 0, 100, 200, 300, 400 };
	int* pint = numbers;
	int* p2 = &numbers[3];

	out << "sizeof(int) = " << sizeof(int) << endl;

	out << "*(pint+1) = " << *(pint + 1)
		<< ", pint[1] = " << pint[1] << endl;

	out << "*(pint+4) = " << *(pint + 4)
		<< ", pint[4] = " << pint[4] << endl;

	out << "p2 - pint = " << p2 - pint << endl;

	out << "p2 == pint = " << boolalpha << (p2 == pint) << endl;
	out << "p2 > pint = " << boolalpha << (p2 > pint) << endl;

	return out.str();
}

TEST(Chapter5, Exercise29) {

	EXPECT_EQ("sizeof(int) = 4\n*(pint+1) = 100, pint[1] = 100\n*(pint+4) = 400, pint[4] = 400\np2 - pint = 3\np2 == pint = false\np2 > pint = true\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}