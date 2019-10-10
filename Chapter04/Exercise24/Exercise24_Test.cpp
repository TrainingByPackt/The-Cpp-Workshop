//Chapter 4 : Exercise 24 

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::string TestCase(std::string name1, std::string name2, std::string name3) {
	std::ostringstream out;
	if (name1 == name2 && name2 == name3)
	{
		out << "\nAll the names are the same.";
	}
	else if (name1 == name2 || name2 == name3 || name1 == name3)
	{
		out << "\nSome of the names matched.";
	}
	out << "\nNames 1 and 2 are " << (!(name1 == name2) ? "different." : "the same.") << std::endl;

	return out.str();
}

TEST(Chapter4, Exercise24) {
	EXPECT_EQ("\nAll the names are the same.\nNames 1 and 2 are the same.\n", TestCase("Packt", "Packt", "Packt"));
	EXPECT_EQ("\nSome of the names matched.\nNames 1 and 2 are different.\n", TestCase("Packt", "Name", "Packt"));
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}