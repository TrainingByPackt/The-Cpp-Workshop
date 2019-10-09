//Chapter 2 : Exercise 9-1

#include "pch.h"
#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string WhileLoop() {
   std::ostringstream out;
   while (false)
   {
      out << "Hello World!";
   }

   return out.str();
}


TEST(Chapter2, Exercise9_1) {
   
   EXPECT_EQ("", WhileLoop());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}