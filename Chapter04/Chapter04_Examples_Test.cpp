//Chapter 4 : Example 1 - Equality

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::string TestCase() {
	std::ostringstream out;
	int myInt1 = 1;
	int myInt2 = 1;
	int myInt3 = 5;

	if (myInt1 == myInt2)
	{
		out << myInt1 << " is equal to " << myInt2 << ".\n";
	}

	if (myInt1 != myInt3)
	{
		out << myInt1 << " is not equal to " << myInt3;
	}

	return out.str();
}

TEST(Chapter4, Example1) {
	EXPECT_EQ("1 is equal to 1.\n1 is not equal to 5", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}


//Chapter 4 : Example 2 - Comparison

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::string TestCase() {
	std::ostringstream out;
	int myInt1 = 1;
	int myInt2 = 1;
	int myInt3 = 5;

	if (myInt1 > myInt2)
	{
		out << myInt1 << " is greater than" << myInt2 << ".\n";
	}

	if (myInt1 < myInt3)
	{
		out << myInt1 << " is less than " << myInt3 << ".\n";
	}

	if (myInt3 >= myInt2)
	{
		out << myInt3 << " is greater than or equal to " << myInt2 << ".\n";
	}

	if (myInt2 <= myInt1)
	{
		out << myInt2 << " is less than or equal to " << myInt1;
	}

	return out.str();
}

TEST(Chapter4, Example2) {
	EXPECT_EQ("1 is less than 5.\n5 is greater than or equal to 1.\n1 is less than or equal to 1", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}


//Chapter 4 : Example 4 (Operator Overloading)

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;
std::ostringstream out;

class MyClass
{
public:
	void operator+ (MyClass const& other)
	{
		out << "Overloaded Operator Called" << std::endl;
		return;
	}
};

std::string TestCase() {
	MyClass A = MyClass();
	MyClass B = MyClass();
	A + B;
	return out.str();
}

TEST(Chapter4, Example4) {
	EXPECT_EQ("Overloaded Operator Called\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}


//Chapter 4 : Example 5 (Bitwise Operators)

#include "pch.h"
#include <iostream>
#include <bitset>
#include "gtest/gtest.h"
using namespace std;

std::string TestCase() {
	std::ostringstream out;

	int myInt1 = 6;     // 00110 when expressed in binary
	int myInt2 = 12;    // 01100 when expressed in binary

						// Binary AND
	out << std::bitset<5>(myInt1 & myInt2) << std::endl;

	// Binary OR
	out << std::bitset<5>(myInt1 | myInt2) << std::endl;

	// Binary Ones Compliment
	out << std::bitset<5>(~myInt1) << std::endl;

	// Binary Left Shift Operator
	out << std::bitset<5>(myInt1 << 2) << std::endl;

	// Binary Right Shift Operator
	out << std::bitset<5>(myInt2 >> 2) << std::endl;

	return out.str();
}

TEST(Chapter4, Example5) {
	EXPECT_EQ("00100\n01110\n11001\n11000\n00011\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}