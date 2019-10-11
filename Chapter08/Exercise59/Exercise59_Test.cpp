//Chapter 8 : Exercise 59

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
class Track
{
public:

	Track(float lengthInSeconds, string trackName)
	{
		m_lengthInSeconds = lengthInSeconds;
		m_trackName = trackName;
	}

	float m_lengthInSeconds;
	string m_trackName;
};

std::string TestCase() {

	Track t(260.0f, "Still Alive");
	out << "My Favourite Song is: " << t.m_trackName << endl;

	t.m_lengthInSeconds = 9405680394634.4895645f;
	t.m_trackName = "S-Club Party";
	out << "My Favourite Song is: " << t.m_trackName;

	return out.str();
}

TEST(Chapter8, Exercise59) {

	EXPECT_EQ("My Favourite Song is: Still Alive\nMy Favourite Song is: S-Club Party", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}