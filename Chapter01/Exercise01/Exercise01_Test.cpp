// Chapter 1 : Exercise 1

#include "pch.h"
#include <iostream>
#include <string>
#include "gtest/gtest.h"

std::string TestCase () {    
   std::ostringstream out;
   out << "Hello World!";
   return out.str();
}

TEST(Chapter1, Example1) {

   EXPECT_EQ("Hello World!", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);
   
   return RUN_ALL_TESTS();
}