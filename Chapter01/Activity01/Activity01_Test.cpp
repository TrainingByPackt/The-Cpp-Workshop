//Chapter 1 : Activity 

 #include "pch.h"
 #include <iostream>
 #include <string>
 #include "gtest/gtest.h"

 using namespace std;

 #define GROUP_1_THRESHOLD 12
 #define GROUP_2_THRESHOLD 28

 #define GROUP_1_NAME "Group A"
 #define GROUP_2_NAME "Group B"
 #define GROUP_3_NAME "Group C"

 std::string GetGroup(int age)
 {
    if (age <= GROUP_1_THRESHOLD)
    {
       return GROUP_1_NAME;
    }
    else if (age <= GROUP_2_THRESHOLD)
    {
       return GROUP_2_NAME;
    }
    else
    {
       return GROUP_3_NAME;
    }
 }

 TEST(Chapter1, Activity) {
   
    EXPECT_EQ("Group A", GetGroup(10));
    EXPECT_EQ("Group B", GetGroup(25));
    EXPECT_EQ("Group C", GetGroup(34));
 }

 int main(int argc, char *argv[])
 {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
 }
