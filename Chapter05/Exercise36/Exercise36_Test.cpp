//Chapter 5 : Exercise 36

#include "pch.h"
#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
struct mydata
{
	char const* name_;
	bool darkside_;
	mydata(char const* name, bool dark)
	{
		name_ = name; darkside_ = dark;
	}
};
mydata cast[3]
{
   { "Darth Vader", true },
	{ "Luke Skywalker", false },
	{ "Han Solo", false }
};

void printname(mydata& data)
{
	out << "Hello. I am " << data.name_ << endl;
	if (data.darkside_)
		out << "I was seduced by the dark side" << endl;
}

std::string TestCase() {
	for (mydata& data : cast)
	{
		printname(data);
	}
	return out.str();
}

TEST(Chapter5, Exercise36) {

	EXPECT_EQ("Hello. I am Darth Vader\nI was seduced by the dark side\nHello. I am Luke Skywalker\nHello. I am Han Solo\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}

