//Chapter 3 : Exercise 19

#include "pch.h"
#include <iostream>
#include "gtest/gtest.h"
using namespace std;
std::ostringstream out;

class MyClass
{
public:
   int myInt = 0;
   bool myBool = false;

   std::string GetString()
   {
      return "Hello World!";
   }
};

struct MyStruct
{
   int myInt = 0;
   int myBool = 0;

   std::string GetString()
   {
      return "Hello World!";
   }
};

std::string TestCase() {
   MyClass classObject;
   out << "classObject::myInt: " << classObject.myInt << "\n";
   out << "classObject::myBool: " << classObject.myBool << "\n";
   out << "classObject::GetString: " << classObject.GetString() << "\n";

   MyStruct structObject;
   out << "\nstructObject::myInt: " << structObject.myInt << "\n";
   out << "structObject::myBool: " << structObject.myBool << "\n";
   out << "structbject::GetString: " << structObject.GetString() << "\n";

   return out.str();
}

TEST(Chapter3, Exercise19) {
   EXPECT_EQ("classObject::myInt: 0\nclassObject::myBool: 0\nclassObject::GetString: Hello World!\n\nstructObject::myInt: 0\nstructObject::myBool: 0\nstructbject::GetString: Hello World!\n", TestCase());
}

int main(int argc, char *argv[])
{
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}