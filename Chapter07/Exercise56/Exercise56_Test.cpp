//Chapter 7 : Exercise 56 

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;

shared_ptr<char[]> func(shared_ptr<char[]> str)
{
	if (!str)
	{
		str.reset(new char[1]);
		str[0] = '\0';
	}
	return str;
}

std::string TestCase() {
	shared_ptr<char[]> null;
	if (null.get() == nullptr)
		out << "null is equal to nullptr" << endl;
	auto result1 = func(null);
	if (result1.get() == nullptr)
		out << "result1 is equal to nullptr" << endl;
	result1 = func(result1);

	return out.str();
}

TEST(Chapter7, Exercise56) {
	EXPECT_EQ("null is equal to nullptr\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
