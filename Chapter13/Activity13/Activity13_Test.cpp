//Chapter 13 : Activity 13

#include "pch.h"
#include <iostream>
#include <memory>
#include <typeinfo>
#include <string>
#include <set>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
void SCRAM()
{
	out << "SCRAM! I mean it. Get away from here!" << endl;
}

bool reactor_safety_check()
{
	static int count = 0;
	++count;
	if (count % 17 == 0)
	{
		throw runtime_error("Sensor glitch");
	}
	else if (count % 69 == 0)
	{
		throw 123;
		//    throw exception();
	}
	else if (count % 199 == 0)
	{
		return false;
	}

	return true;
}

std::string TestCase() {
	bool continue_flag;
	do
	{
		try
		{
			continue_flag = reactor_safety_check();
		}
		catch (runtime_error & e)
		{
			out << "caught runtime error " << e.what() << endl;
		}
		catch (exception & e)
		{
			out << "caught exception " << e.what() << endl;
			SCRAM();
			break;
		}
		catch (...)
		{
			out << "caught unknown exception type" << endl;
			SCRAM();
			break;
		}
	} while (continue_flag == true);
	out << "shutting down" << endl;

	return out.str();
}

TEST(Chapter13, Activity13) {

	EXPECT_EQ("caught runtime error Sensor glitch\ncaught runtime error Sensor glitch\ncaught runtime error Sensor glitch\ncaught runtime error Sensor glitch\ncaught unknown exception type\nSCRAM! I mean it. Get away from here!\nshutting down\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}