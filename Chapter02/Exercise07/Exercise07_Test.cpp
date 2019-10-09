//Chapter 2 : Exercise 7

#include "pch.h"
#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string Menu(int number) {
	std::ostringstream out;
	switch (number)
	{
	case 1:
		out << "Fries: $0.99\n";
		break;

	case 2:
		out << "Burger: $1.25\n";
		break;

	case 3:
		out << "Shake: $1.50\n";
		break;

	default:
		out << "Invalid choice.";
		break;
	}

	return out.str();
}


TEST(Chapter2, Exercise7) {

	EXPECT_EQ("Fries: $0.99\n", Menu(1));
	EXPECT_EQ("Burger: $1.25\n", Menu(2));
	EXPECT_EQ("Shake: $1.50\n", Menu(3));
	EXPECT_EQ("Invalid choice.", Menu(4));
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
