//Chapter 7 : Example 3 (Problem with the code, a return value is missing, Pls see the text in bold and italic)

#include "pch.h"
#include <iostream>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;

struct noisy_and_big
{
	noisy_and_big() { out << "constructing noisy" << endl; }
	~noisy_and_big() { out << "destroying noisy" << endl; }
	char big_buffer_[10000];
};

noisy_and_big* get_noisy_and_big(char const* str)
{
	noisy_and_big* ownedp = new noisy_and_big;
	strcpy(ownedp->big_buffer_, str);
	return ownedp;
}

std::string TestCase() {

	noisy_and_big* newownedp = get_noisy_and_big("a big, big buffer");
	out << "noisy and big: " << newownedp->big_buffer_ << endl;

	delete newownedp;

	return out.str();
}

TEST(Chapter7, Example3) {

	EXPECT_EQ("constructing noisy\nnoisy and big: a big, big buffer\ndestroying noisy\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}