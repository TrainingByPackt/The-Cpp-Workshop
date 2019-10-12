//Chapter 13 : Exercise 83

#include "pch.h"
#include <iostream>
#include <memory>
#include <typeinfo>
#include <string>
#include <set>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
class noisy
{
	char const* s_;
public:
	noisy(char const* s) { out << "constructing " << (s_ = s) << endl; }
	~noisy() { out << "destroying " << s_ << endl; }
};

int deeply_nested()
{
	auto n = make_unique<noisy>("deeply_nested");

	throw logic_error("totally illogical");
	return 0;
}

int intermediate()
{
	noisy n("intermediate");

	int rc = deeply_nested();
	out << "after calling deeply_nested()" << endl;
	return rc;
}

std::string TestCase() {
	try
	{
		auto n = make_unique<noisy>("try in main");

		int rc = intermediate();
		out << "intermediate() returned " << rc << endl;
	}
	catch (exception & e)
	{
		out << "in catch: exception: " << e.what() << endl;
	}
	out << "ending main" << endl;

	return out.str();
}

TEST(Chapter13, Exercise83) {

	EXPECT_EQ("constructing try in main\nconstructing intermediate\nconstructing deeply_nested\ndestroying deeply_nested\ndestroying intermediate\ndestroying try in main\nin catch: exception: totally illogical\nending main\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}