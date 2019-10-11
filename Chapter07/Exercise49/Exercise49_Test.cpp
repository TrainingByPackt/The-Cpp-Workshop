//Chapter 7 : Exercise 49

#include "pch.h"
#include <iostream>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;

class noisy
{
	char const* s_;
public:
	noisy(char const* s)
	{
		out << "constructing " << s << endl; s_ = s;
	}
	~noisy()
	{
		out << "destroying " << s_ << endl;
	}
};

void func(char const* s)
{
	noisy func(s);
}

noisy f("global 1");
noisy ff("global 2");

std::string TestCase() {

	noisy n1("main() function local 1");
	func("function local 2");

	{
		noisy n("block local");
		func("function local 3");
	}

	return out.str();
}

TEST(Chapter7, Exercise49) {

	EXPECT_EQ("constructing global 1\nconstructing global 2\nconstructing main() function local 1\nconstructing function local 2\ndestroying function local 2\nconstructing block local\nconstructing function local 3\ndestroying function local 3\ndestroying block local\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}