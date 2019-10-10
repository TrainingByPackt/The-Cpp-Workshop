//Chapter 4 : Exercise 25

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;
std::ostringstream out;

class Person
{
public:

	Person(int age, std::string name) :
		age(age), name(name)
	{
	};

	float age = 0;
	std::string name = "";
	bool operator== (Person const& other)
	{
		return ((age == other.age) && (name == other.name));
	}
};


std::string TestCase() {
	Person PersonA = Person(27, "Lucy");
	Person PersonB = Person(27, "Lucy");
	Person PersonC = Person(27, "Susan");

	out << (PersonA == PersonB) << std::endl;
	out << (PersonB == PersonC) << std::endl;

	return out.str();
}

TEST(Chapter4, Exercise25) {
	EXPECT_EQ("1\n0\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
