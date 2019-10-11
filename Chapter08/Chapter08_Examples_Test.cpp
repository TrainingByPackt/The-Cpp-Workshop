//Chapter 8 : Example 1 (Shallow copy or Deep copy)

#include "pch.h"
#include <iostream>
#include <memory>
#include <typeinfo>
#include <string>
#include <set>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
class Track
{
public:

	Track(float lengthInSeconds = 0.0f, string trackName = "not set")
	{
		m_lengthInSeconds = lengthInSeconds;
		m_trackName = trackName;
	}

	// m_ prefix added to member variables, to avoid naming conflicts with parameter names
	float m_lengthInSeconds;
	string m_trackName;
};

std::string TestCase() {
	Track track(200.0f, "Still Alive");

	Track track2 = track; // default copy constructor is called

	out << "Track Name = " << track.m_trackName << endl;
	out << "Track Length = " << track.m_lengthInSeconds << endl;

	out << "Track Name = " << track2.m_trackName << endl;
	out << "Track Length = " << track2.m_lengthInSeconds << endl;

	return out.str();
}

TEST(Chapter8, Example1) {

	EXPECT_EQ("Track Name = Still Alive\nTrack Length = 200\nTrack Name = Still Alive\nTrack Length = 200\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}