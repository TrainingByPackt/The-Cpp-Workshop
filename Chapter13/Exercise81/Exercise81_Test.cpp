//Chapter 13 : Exercise 81

#include "pch.h"
#include <iostream>
#include <memory>
#include <typeinfo>
#include <string>
#include <set>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
int deeply_nested()
{
	throw 123;
	return 0;
}
std::string TestCase() {
	try
	{
		deeply_nested();
	}
	catch (...)
	{
		out << "in catch ..." << endl;
	}

	out << "in main(), after try/catch" << endl;

	return out.str();
}

TEST(Chapter13, Exercise81) {

	EXPECT_EQ("in catch ...\nin main(), after try/catch\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}