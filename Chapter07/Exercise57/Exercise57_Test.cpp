//Chapter 7 : Exercise 57

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

void UnitMainTest()
{
	shared_ptr<noisy> u1(new noisy);
	shared_ptr<noisy> u2 = make_shared<noisy>();
	shared_ptr<noisy> u3 = u2;
	u2.reset();
}

std::string TestCase() {
	UnitMainTest();
	return out.str();
}

TEST(Chapter7, Exercise57) {
	EXPECT_EQ("constructing noisy\nconstructing noisy\ndestroying noisy\ndestroying noisy\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
