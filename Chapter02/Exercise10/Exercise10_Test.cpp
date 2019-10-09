//Chapter 2 : Exercise 10

#include "pch.h"
#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string ForLoop() {
   std::ostringstream out;

   for (int i = 0; i < 5; ++i)
   {
      out << i;
   }


   return out.str();
}


TEST(Chapter2, Exercise10) {
   
   EXPECT_EQ("01234", ForLoop());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}