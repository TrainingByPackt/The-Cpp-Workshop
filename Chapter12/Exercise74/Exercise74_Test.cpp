//Chapter 12 : Exercise 74

#include "pch.h"
#include <iostream>
#include <memory>
#include <typeinfo>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;

bool isPalindrome(const string& str)
{
	// make a copy of the string
	string s(str.begin(), str.end());

	// remove any spaces or punctuation
	s.erase(remove_if(s.begin(), s.end(), [](const char& c) { return ispunct(c) || isspace(c); }), s.end());
	// lower case what's left
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	// create a reversed version of the string
	string sr(s.rbegin(), s.rend());

	// compare them
	return (s == sr);
}

std::string TestCase() {
	string str = "Never odd or even";

	out << "'" << str << "'" << " is a palindrome? " << (isPalindrome(str) ? "YES" : "NO") << endl;

	return out.str();
}

TEST(Chapter12, Exercise74) {

	EXPECT_EQ("'Never odd or even' is a palindrome? YES\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}