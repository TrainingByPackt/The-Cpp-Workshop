//Chapter 6 : Exercise 38

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
std::string ClassDynamicCreation() {

	noisy N(1);
	noisy* p = new noisy(2);
	delete p;
	return out.str();
}

TEST(Chapter6, Exercise38) {

	EXPECT_EQ("constructing noisy 1\nconstructing noisy 2\ndestroying noisy 2\n", ClassDynamicCreation());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}