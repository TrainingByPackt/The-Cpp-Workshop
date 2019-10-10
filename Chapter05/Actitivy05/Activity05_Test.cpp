//Chapter 5 : Acitivity 05

#include "pch.h"
#include <iostream>
#include <string>
#include "gtest/gtest.h"

std::ostringstream out;
char const* array[26]
{ "alpha", "bravo", "charlie", "delta", "echo" };

int printarray(char const** begin, char const** end, int& count)
{
	if (begin == nullptr || end == nullptr ||
		begin > end || end - begin > 26)
	{
		return 0;
	}

	for (count = 0; begin < end; ++begin)
	{
		if (*begin != nullptr)
		{
			++count;
			out << *begin << std::endl;
		}
	}
	return 1;
}

std::string TestCase() {
	int count;
	if (printarray(nullptr, nullptr, count) == 0 || count != 0)
	{
		out << "error in printarray() call 1" << std::endl;
	}
	else
	{
		out << "count = " << count << std::endl;
	}

	if (printarray(array, &array[4], count) == 0 || count != 4)
	{
		out << "error in printarray() call 2" << std::endl;
	}
	else
	{
		out << "count = " << count << std::endl;
	}

	if (printarray(&array[4], &array[3], count) == 0 || count != 0)
	{
		out << "error in printarray() call 3" << std::endl;
	}
	else
	{
		out << "count = " << count << std::endl;
	}

	if (printarray(&array[4], &array[10], count) == 0 || count != 1)
	{
		out << "error in printarray() call 4" << std::endl;
	}
	else
	{
		out << "count = " << count << std::endl;
	}

	if (printarray(&array[0], &array[100], count) == 0 || count != 0)
	{
		out << "error in printarray() call 5" << std::endl;
	}
	else
	{
		out << "count = " << count << std::endl;
	}

	return out.str();
}

TEST(Chapter5, Activity05) {

	EXPECT_EQ("error in printarray() call 1\nalpha\nbravo\ncharlie\ndelta\ncount = 4\nerror in printarray() call 3\necho\ncount = 1\nerror in printarray() call 5\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}