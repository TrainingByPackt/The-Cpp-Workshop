//Chapter 12 : Exercise 73

#include "pch.h"
#include <iostream>
#include <memory>
#include <typeinfo>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;

std::string TestCase() {
	string str;
	string str1("Hello, I'm a string!");
	string str2(str1);
	string str3(str1, 0, 5);
	string str4("Hello, I'm a string!", 0, 5);
	string str5(10, 'x');
	string str6(str4.begin() + 1, str4.end() - 1);

	out << str << endl;
	out << str1 << endl;
	out << str2 << endl;
	out << str3 << endl;
	out << str4 << endl;
	out << str5 << endl;
	out << str6 << endl;

	return out.str();
}

TEST(Chapter12, Exercise73) {

	EXPECT_EQ("\nHello, I'm a string!\nHello, I'm a string!\nHello\nHello\nxxxxxxxxxx\nell\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}