//Chapter 8 : Activity 08

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


class VideoClip
{
public:

   VideoClip()
   {
      m_videoLength = 0;
      m_videoName = "NOT SET";
      m_dataLength = 0;
      m_data = 0;
   }

   VideoClip(float videoLength, string videoName, const char* data)
   {
      m_videoLength = videoLength;
      m_videoName = videoName;


      m_dataLength = strlen(data);
      m_data = new char[m_dataLength + 1];
      strcpy(m_data, data);
   }

   VideoClip(const VideoClip& vc)
   {
      m_videoLength = vc.m_videoLength;
      m_videoName = vc.m_videoName;
      m_dataLength = vc.m_dataLength;


      m_data = new char[m_dataLength + 1];
      strcpy(m_data, vc.m_data);
   }

   VideoClip& operator=(const VideoClip& rhs)
   {
      if (this != &rhs)
      {
         m_videoLength = rhs.m_videoLength;
         m_videoName = rhs.m_videoName;
         m_dataLength = rhs.m_dataLength;
         char* newData = new char[m_dataLength];
         strcpy(newData, rhs.m_data);

         delete[] m_data;
         m_data = newData;
      }
      return *this;
   }

   ~VideoClip()
   {
      delete[] m_data;
   }

   float m_videoLength;
   string m_videoName;

   int m_dataLength;
   char* m_data;

};

std::string TestCase() {
   VideoClip vc1(10.0f, "Halloween (2019)", "dfhdhfidghirhgkhrfkghfkg");
   VideoClip vc2(20.0f, "Halloween (1978)", "jkghdfjkhgjhgfjdfg");
   VideoClip vc3(50.0f, "The Shining", "kotriothgrngirgr");

   out << vc1.m_videoLength << " " << vc1.m_videoName << " " << vc1.m_data << endl;
   out << vc2.m_videoLength << " " << vc2.m_videoName << " " << vc2.m_data << endl;
   out << vc3.m_videoLength << " " << vc3.m_videoName << " " << vc3.m_data << endl;

   VideoClip vc4 = vc1;

   vc2 = vc4;

   out << vc1.m_videoLength << " " << vc1.m_videoName << " " << vc1.m_data << endl;
   out << vc2.m_videoLength << " " << vc2.m_videoName << " " << vc2.m_data << endl;
   out << vc3.m_videoLength << " " << vc3.m_videoName << " " << vc3.m_data << endl;
   out << vc4.m_videoLength << " " << vc4.m_videoName << " " << vc4.m_data << endl;

   return out.str();
}

TEST(Chapter8, Activity08) {

   EXPECT_EQ("10 Halloween (2019) dfhdhfidghirhgkhrfkghfkg\n20 Halloween (1978) jkghdfjkhgjhgfjdfg\n50 The Shining kotriothgrngirgr\n10 Halloween (2019) dfhdhfidghirhgkhrfkghfkg\n10 Halloween (2019) dfhdhfidghirhgkhrfkghfkg\n50 The Shining kotriothgrngirgr\n10 Halloween (2019) dfhdhfidghirhgkhrfkghfkg", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}
