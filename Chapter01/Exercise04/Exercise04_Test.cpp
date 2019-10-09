// Chapter 1 : Exercise 4

 #include "pch.h" 
 #include <iostream>
 #include <string>
 #include "gtest/gtest.h"

 using namespace std;

 int Max(int a, int b)
 {
    if (a > b)
    {
       return a;
    }
    else
    {
       return b;
    }
 }

 TEST(Chapter1, Exercise4) {

    EXPECT_EQ(10, Max(10, 1));
    EXPECT_EQ(100, Max(10, 100));
    EXPECT_EQ(20, Max(10, 20));
 }

 int main(int argc, char *argv[])
 {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
 }