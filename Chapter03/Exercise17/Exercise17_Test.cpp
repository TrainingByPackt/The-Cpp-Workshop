//Chapter 3 : Exercise 17 

#include "pch.h"
#include <iostream>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
std::vector<int> myVector{ 1, 2, 3, 4, 5 };
void PrintVector()
{
	for (int i = 0; i < myVector.size(); ++i)
	{
		out << myVector[i];
	}

	out << "\n\n";
}
std::string TestCase() {
	myVector.pop_back();
	PrintVector();

	myVector.push_back(6);
	PrintVector();

	myVector.erase(myVector.begin() + 1);
	PrintVector();

	myVector.insert(myVector.begin() + 3, 8);
	PrintVector();

	return out.str();
}

TEST(Chapter3, Exercise17) {
	EXPECT_EQ("1234\n\n12346\n\n1346\n\n13486\n\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}