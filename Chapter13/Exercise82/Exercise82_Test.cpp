//Chapter 13 : Exercise 82

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
	string("xyzzy").at(100);
	return 0;
}
std::string TestCase() {
	try
	{
		deeply_nested();
	}
	catch (exception & e)
	{
		out << "caught " << e.what() << endl;
	}
	catch (...)
	{
		out << "in catch ..." << endl;
	}

	out << "in main(), after try/catch" << endl;
	return out.str();
}

TEST(Chapter13, Exercise82) {

	EXPECT_EQ("caught invalid string position\nin main(), after try/catch\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}