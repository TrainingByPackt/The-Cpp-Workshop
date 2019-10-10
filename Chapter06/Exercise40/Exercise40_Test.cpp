//Chapter 6 : Exercise 40

#include "pch.h"
#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
struct noisy
{
	noisy() { out << "constructing noisy" << endl; }
	~noisy() { out << "destroying noisy" << endl; }
};


std::string TestCase() {
	noisy* p = new noisy[3];
	delete[] p;
	return out.str();
}

TEST(Chapter6, Exercise40) {

	EXPECT_EQ("constructing noisy\nconstructing noisy\nconstructing noisy\ndestroying noisy\ndestroying noisy\ndestroying noisy\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}