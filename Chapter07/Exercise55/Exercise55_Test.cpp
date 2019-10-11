//Chapter 7 : Exercise 55

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;

struct noisy
{
	noisy() { out << "constructing noisy" << endl; }
	~noisy() { out << "destroying noisy" << endl; }
};

unique_ptr<noisy> func()
{
	return make_unique<noisy>();
}

void UnitMainTest() {
	auto u1 = func();
}

std::string TestCase() {
	UnitMainTest();
	return out.str();
}

TEST(Chapter7, Exercise55) {
	EXPECT_EQ("constructing noisy\ndestroying noisy\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
