//Chapter 8 : Exercise 61

#include "pch.h"
#include <iostream>
#include <memory>
#include <typeinfo>
#include <string>
#include <cstring>
#include <set>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;

class Track
{
public:
	// added additional artist name constructor parameter
	Track(float lengthInSeconds = 0.0f, string trackName = "not set", string artistName = "not set", const char* data = NULL)
	{
		m_lengthInSeconds = lengthInSeconds;
		m_trackName = trackName;

		m_artistName = artistName;

		// create the sample clip from data
		m_dataSize = strlen(data);
		m_data = new char[m_dataSize + 1];
		strcpy(m_data, data);
	}

	Track(const Track& track)
	{
		// these can be shallow copied
		m_lengthInSeconds = track.m_lengthInSeconds;
		m_trackName = track.m_trackName;
		m_artistName = track.m_artistName;
		m_dataSize = track.m_dataSize;

		// allocate memory for the copied pointer
		m_data = new char[m_dataSize + 1];

		// copy the value from the old object
		strcpy(m_data, track.m_data);
	}

	Track& operator=(const Track& track)
	{
		// check for self assignment
		if (this != &track)
		{
			// these can be shallow copied
			m_lengthInSeconds = track.m_lengthInSeconds;
			m_trackName = track.m_trackName;
			m_artistName = track.m_artistName;
			m_dataSize = track.m_dataSize;
			// allocate new memory and copy the existing data from the passed in object
			char* newData = new char[m_dataSize];
			strcpy(newData, track.m_data);
			// since this is an already existing object we must deallocate existing memory
			delete[] m_data;
			// assign the new data 
			m_data = newData;
		}

		return *this;
	}

	~Track()
	{
		delete[] m_data;
	}

	void SetData(float lengthInSeconds = 0.0f, string trackName = "not set", const char* newData = NULL)
	{
		m_lengthInSeconds = lengthInSeconds;
		m_trackName = trackName;

		// delete the array so it can be recreated
		delete[] m_data;

		// create the sample clip from data
		m_dataSize = strlen(newData);
		m_data = new char[m_dataSize + 1];
		strcpy(m_data, newData);
	}

	// m_ prefix added to member variables, to avoid naming conflicts with parameter names
	float m_lengthInSeconds;
	string m_trackName;

	// additional artist name string member variable
	string m_artistName;

	// sample clip data
	int m_dataSize;
	char* m_data;
};


std::string TestCase() {
	Track track(200.0f, "Still Alive", "GlaDos", "f651270d6011098375db09912b03e5e7");

	// copy the first track with the artist name
	Track track2 = track;

	// set the new needed data
	track2.SetData(300.0f, "Want You Gone", "db6fd7d74393b375344010a0c9cc4535");

	track2 = track;

	out << "Track 1" << endl;
	out << "Artist = " << track.m_artistName << endl;
	out << "Track Name = " << track.m_trackName << endl;
	out << "Track Length = " << track.m_lengthInSeconds << endl;
	out << "Track Data = " << track.m_data << endl;
	out << endl;
	out << "Track 2" << endl;
	out << "Artist = " << track2.m_artistName << endl;
	out << "Track Name = " << track2.m_trackName << endl;
	out << "Track Length = " << track2.m_lengthInSeconds << endl;
	out << "Track Data = " << track2.m_data << endl;

	return out.str();
}

TEST(Chapter8, Exercise61) {

	EXPECT_EQ("Track 1\nArtist = GlaDos\nTrack Name = Still Alive\nTrack Length = 200\nTrack Data = f651270d6011098375db09912b03e5e7\n\nTrack 2\nArtist = GlaDos\nTrack Name = Want You Gone\nTrack Length = 300\nTrack Data = db6fd7d74393b375344010a0c9cc4535\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
