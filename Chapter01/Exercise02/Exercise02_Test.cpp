// Chapter 1 : Exercise 2

 #include "pch.h"
 #include <iostream>
 #include <string>
 #include "gtest/gtest.h"

 #define GRADE_C_THRESHOLD 25
 #define GRADE_B_THRESHOLD 50
 #define GRADE_A_THRESHOLD 75

 std::string TestCase (int value) {
    std::ostringstream out;
    if (value < GRADE_C_THRESHOLD)
    {
       out << "Fail";
    }
    else if (value < GRADE_B_THRESHOLD)
    {
       out << "Pass: Grade C";
    }
    else if (value < GRADE_A_THRESHOLD)
    {
       out << "Pass: Grade B";
    }
    else
    {
       out << "Pass: Grade A";
    }
    return out.str();
 }

 TEST(Chapter1, Example2) {

    EXPECT_EQ("Fail", TestCase(20));
    EXPECT_EQ("Pass: Grade C", TestCase(40));
    EXPECT_EQ("Pass: Grade B", TestCase(60));
    EXPECT_EQ("Pass: Grade A", TestCase(80));
 }

 int main(int argc, char *argv[])
 {
    ::testing::InitGoogleTest(&argc, argv);
   
    return RUN_ALL_TESTS();
 }