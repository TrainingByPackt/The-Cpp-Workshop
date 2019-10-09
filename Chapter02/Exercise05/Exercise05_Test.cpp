//Chapter 2 : Exercise 5

#include "pch.h"
#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string GetNumber(int number) {

   if (number < 10)
   {
      return "The number you entered was less than 10!\n";
   }
   else if (number > 10)
   {
      return "The number you entered was greater than 10!\n";
   }
}


TEST(Chapter2, Exercise5) {
   
   EXPECT_EQ("The number you entered was less than 10!\n", GetNumber(2));
   EXPECT_EQ("The number you entered was greater than 10!\n", GetNumber(34));
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}