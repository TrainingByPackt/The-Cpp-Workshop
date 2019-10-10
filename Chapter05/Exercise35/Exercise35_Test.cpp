//Chapter 5 : Exercise 35

#include "pch.h"
#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
struct mydata
{
	char const* name_;
	bool hero_;
};
mydata heroes[]
{
   { "Spider Man", true },
	{ "The Joker", false },
	{ "Doctor Octopus", false },
	{ "Thor", true },
	{ "Batman", true },
	{ "Loki", false }
};

void printdata(mydata* p)
{
	out << "Hello. I am " << (*p).name_ << ". ";
	if (p->hero_)
		out << "I am a hero." << endl;
	else
		out << "I am a villain." << endl;
}

std::string TestCase() {
	out << sizeof(mydata) << " " << sizeof(mydata*) << endl;

	for (mydata* p = heroes; p < heroes + 6; ++p)
	{
		printdata(p);
	}

	return out.str();
}

TEST(Chapter5, Exercise35) {

	EXPECT_EQ("8 4\nHello. I am Spider Man. I am a hero.\nHello. I am The Joker. I am a villain.\nHello. I am Doctor Octopus. I am a villain.\nHello. I am Thor. I am a hero.\nHello. I am Batman. I am a hero.\nHello. I am Loki. I am a villain.\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}