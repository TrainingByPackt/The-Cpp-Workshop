//Chapter 7 : Exercise52 (Answer has address so result will vary every iteration)

#include "pch.h"
#include <iostream>
#include <memory>
#include <cstring>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;

struct noisy
{
	noisy() { out << "default constructing noisy" << endl; }
	noisy(int i) { out << "constructing noisy: arg " << i << endl; }
	~noisy() { out << "destroying noisy" << endl; }
};

std::string TestCase() {

	unique_ptr<noisy> u1(new noisy);
	unique_ptr<noisy> u2;
	u2.reset(new noisy(100));
	unique_ptr<noisy[]> u3(new noisy[3]);
	unique_ptr<noisy[]> u4(new noisy[2]{ 1 });
	unique_ptr<noisy> u5;

	out << "before transfer of ownership u1 = " << u1.get()
		<< ", u5 = " << u5.get() << endl;
	u5.reset(u1.release());
	out << "after transfer of ownership u1 = " << u1.get()
		<< ", u5 = " << u5.get() << endl;
	u1 = move(u5);
	out << "after second transfer u1 = " << u1.get()
		<< ", u5 = " << u5.get() << endl;

	unique_ptr<char[]> buf(new char[20]);
	strcpy(buf.get(), "xyzzy");
	out << "buf = " << buf.get() << endl;

	return out.str();
}

TEST(Chapter7, Exercise52) {

	EXPECT_EQ("default constructing noisy\nconstructing noisy: arg 100\ndefault constructing noisy\ndefault constructing noisy\ndefault constructing noisy\nconstructing noisy: arg 1\ndefault constructing noisy\nbefore transfer of ownership u1 = 00F70B40, u5 = 00000000\nafter transfer of ownership u1 = 00000000, u5 = 00F70B40\nafter second transfer u1 = 00F70B40, u5 = 00000000\nbuf = xyzzy\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}