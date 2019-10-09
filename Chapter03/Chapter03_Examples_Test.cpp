//Chapter 3 : Example 6 (Between exercise 18 and 19)

#include "pch.h"
#include <iostream>
#include "gtest/gtest.h"
using namespace std;
std::ostringstream out;

class MyClass
{
public:
   MyClass()
   {
      out << "My Class Constructor Called\n";
      myPublicInt = 5;
   }

   int myPublicInt = 0;    
   ~MyClass()
   {
      out << "My Class Destructor Called\n";
   }
};

std::string TestCase() { 
   {
      out << "Application started\n";

      MyClass testClass;

      out << testClass.myPublicInt << "\n";
   }
   return out.str();
}

TEST(Chapter3, Example6) {
   EXPECT_EQ("Application started\nMy Class Constructor Called\n5\nMy Class Destructor Called\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}



//Chapter 3 : Example 8 (After Exercise 20 - Static keyword)

#include "pch.h"
#include <iostream>
#include "gtest/gtest.h"
using namespace std;
std::ostringstream out;

int MyInt()
{
   int myInt = 0;
   return ++myInt;
}

std::string TestCase() {
   for (int i = 0; i < 5; ++i)
   {
      out << MyInt();
   }
   return out.str();
}

TEST(Chapter3, Example8) {
   EXPECT_EQ("11111", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}
