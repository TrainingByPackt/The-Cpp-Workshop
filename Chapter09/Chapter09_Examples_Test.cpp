//Chapter 9 : Example 1 

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
class Track
{
public:

	// declare a constant value for maximum track length
	const float MAX_TRACK_LENGTH = 600.0f;

	Track(float lengthInSeconds, string trackName)
	{
		m_lengthInSeconds = lengthInSeconds;
		m_trackName = trackName;
	}

	float getLength() { return m_lengthInSeconds; }
	string getName() { return m_trackName; }

	void setName(string newTrackName)
	{
		// if S-Club is not found set the track name - otherwise do nothing
		if (newTrackName.find("S-Club") == string::npos)
		{
			m_trackName = newTrackName;
		}
	}

	void setLength(float newTrackLength)
	{
		if (newTrackLength < MAX_TRACK_LENGTH && newTrackLength > 0) // no prog metal for us!
		{
			m_lengthInSeconds = newTrackLength;
		}
	}

private:

	float m_lengthInSeconds;
	string m_trackName;
};

std::string TestCase() {
	// create
	Track t(260.0f, "Still Alive");

	out << "My Favourite Song is: " << t.getName() << endl;
	out << "It is :" << t.getLength() / 60.0f << " minutes long" << endl;

	t.setName("S-Club Party"); // this again!
	t.setLength(315576000000.0f); // 10 milennia

	out << "My Favourite Song is: " << t.getName() << endl;
	out << "It is :" << t.getLength() / 60.0f << " minutes long";

	return out.str();
}

TEST(Chapter9, Example1) {

	EXPECT_EQ("My Favourite Song is: Still Alive\nIt is :4.33333 minutes long\nMy Favourite Song is: Still Alive\nIt is :4.33333 minutes long", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}