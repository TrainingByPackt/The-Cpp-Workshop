//Chapter 2 : Exercise 9-2

#include "pch.h"
#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string WhileLoop() {
   std::ostringstream out;

   do
   {
      out << "Hello World!";
   } while (false);


   return out.str();
}


TEST(Chapter2, Exercise9_2) {
   
   EXPECT_EQ("Hello World!", WhileLoop());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}