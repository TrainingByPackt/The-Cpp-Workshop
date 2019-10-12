//Chapter 12 : Exercise 79

#include "pch.h"
#include <iostream>
#include <memory>
#include <typeinfo>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;

std::string TestCase() {
	set<int> intSet;
	multiset<int> intMultiset;
	for (unsigned int i = 0; i < 100; i++)
	{
		intMultiset.insert(1 + rand() % 100);
	}
	for (auto i : intMultiset)
	{
		intSet.insert(i);
	}
	out << "there are " << intSet.size() << " unique elements in the multiset";

	return out.str();
}

TEST(Chapter12, Exercise79) {

	EXPECT_EQ("there are 65 unique elements in the multiset", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}