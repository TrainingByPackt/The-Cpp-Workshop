//Chapter 12 : Exercise 76

#include "pch.h"
#include <iostream>
#include <memory>
#include <typeinfo>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
class Track
{
public:

	Track(float length, string name, int popularity) : m_trackLength(length), m_trackName(name), m_popularityRating(popularity) {}

	float getLength() const { return m_trackLength; }
	string getName() const { return m_trackName; }
	int getPopularity() const { return m_popularityRating; }

private:

	float m_trackLength;
	string m_trackName;
	int m_popularityRating;
};
bool trackLengthCompare(const Track& t1, const Track& t2)
{
	return (t1.getLength() < t2.getLength());
}

std::string TestCase() {
	vector<Track> tracks;

	tracks.push_back(Track(199.0f, "God's Plan", 100));
	tracks.push_back(Track(227.0f, "Hold On, We're Going Home", 95));
	tracks.push_back(Track(182.0f, "The Motto", 80));

	sort(tracks.begin(), tracks.end(), trackLengthCompare);

	for (auto t : tracks)
	{
		out << t.getName() << endl;
	}

	return out.str();
}

TEST(Chapter12, Exercise76) {

	EXPECT_EQ("The Motto\nGod's Plan\nHold On, We're Going Home\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}