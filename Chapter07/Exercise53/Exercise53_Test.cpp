//Chapter 7 : Exercise 53

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

std::string TestCase() {
	unique_ptr<noisy> u1(new noisy);
	unique_ptr<noisy> u2 = make_unique<noisy>();
	auto u3 = make_unique<noisy[]>(4);

	return out.str();
}

TEST(Chapter7, Exercise53) {
	EXPECT_EQ("constructing noisy\nconstructing noisy\nconstructing noisy\nconstructing noisy\nconstructing noisy\nconstructing noisy\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
