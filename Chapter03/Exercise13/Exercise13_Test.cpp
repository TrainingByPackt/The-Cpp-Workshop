//Chapter 3 : Exercise 13

#include "pch.h"
#include <iostream>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;

void PrintVector()
{
   std::vector<int> myVector;
   for (int i = 0; i < myVector.size(); ++i)
   {
      out << myVector[i];
   }

   out << "\n\n";
}
std::string TestCase() {
   PrintVector();
   return out.str();
}

TEST(Chapter3, Example4) {
   EXPECT_EQ("\n\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}