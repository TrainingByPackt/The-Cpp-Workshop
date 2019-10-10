//Chapter 6 : Example 44

#include "pch.h"
#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
class noisy
{
	int i_;
public:
	noisy(int i) : i_(i)
	{
		out << "constructing noisy " << i << endl;
	}
	~noisy()
	{
		out << "destroying noisy " << i_ << endl;
	}
};

std::string TestCase() {
	noisy N(1);
	noisy* p = new noisy(2);
	p = new noisy(3);
	delete p;

	return out.str();
}

TEST(Chapter6, Exercise44) {

	EXPECT_EQ("constructing noisy 1\nconstructing noisy 2\nconstructing noisy 3\ndestroying noisy 3\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}