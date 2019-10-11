//Chapter 8 : Exercise 58 

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
class Track
{
public:
   Track()
   {
      lengthInSeconds = 0.0f;
      trackName = "not set";
   }

   float lengthInSeconds;
   string trackName;
};


std::string TestCase() {
   
   Track track;

   out << "Track Name = " << track.trackName << endl;
   out << "Track Length = " << track.lengthInSeconds << endl;

   return out.str();
}

TEST(Chapter8, Exercise58) {

   EXPECT_EQ("Track Name = not set\nTrack Length = 0\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}