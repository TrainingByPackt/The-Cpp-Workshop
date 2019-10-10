//Chapter 5 : Exercise 34

#include "pch.h"
#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

void copychars(char* from, char* to, int count)
{
	if (from == nullptr || to == nullptr)
		return;

	while (count-- > 0)
	{
		*to++ = *from++;
	}
}

std::string TestCase() {
	std::ostringstream out;
	char string[]{ "uvwxyz" };
	char buffer[10];
	copychars(string, buffer, 7);
	out << buffer << endl;
	return out.str();
}

TEST(Chapter5, Exercise34) {

	EXPECT_EQ("uvwxyz\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}