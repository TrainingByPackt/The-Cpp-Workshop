//Chapter 6 : Exercise 39

#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string ArrayDynamicCreation() {
	std::ostringstream out;

	char const* cp = "arbitrary null terminated text string";
	char* buffer = new char[strlen(cp) + 1];
	strcpy(buffer, cp);
	out << "buffer = " << buffer << endl;
	delete[] buffer;

	return out.str();
}

TEST(Chapter6, Exercise39) {

	EXPECT_EQ("buffer = arbitrary null terminated text string\n", ArrayDynamicCreation());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}