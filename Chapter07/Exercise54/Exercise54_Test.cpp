//Chapter 7 : Exercise 54 

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
class autobuf
{
	unique_ptr<noisy> np_;
	unique_ptr<char[]> ptr_;
public:
	autobuf(char const* str);
	char* get();
};

autobuf::autobuf(char const* str)
	: np_(make_unique<noisy>()),
	ptr_(make_unique<char[]>(strlen(str) + 1))
{
	strcpy(ptr_.get(), str);
}

char* autobuf::get()
{
	return ptr_.get();
}

void UnitMainTest() {
	autobuf buffer("my favorite test string");
	out << "Hello World! " << buffer.get() << endl;
}

std::string TestCase() {
	UnitMainTest();
	return out.str();
}

TEST(Chapter7, Exercise54) {
	EXPECT_EQ("constructing noisy\nHello World! my favorite test string\ndestroying noisy\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}