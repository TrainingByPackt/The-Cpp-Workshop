//Chapter 2 : Activity 2

#include "pch.h"
#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::string GuessNumber(int guess, int minNumber, int maxNumber) {
	std::ostringstream out;

	int randomNumber = 0;
	// Generate random number within range.
	srand((unsigned)time(0));
	randomNumber = rand() % (maxNumber - minNumber + 1) + minNumber;

	if (guess == randomNumber)
	{
		out << "Well done, you guessed the number!\n";
		return out.str();
	}

	out << "Your guess was too " << (guess < randomNumber ? "low. " : "high. ");

	return out.str();
}

TEST(Chapter2, Activity2) {

	EXPECT_EQ("Your guess was too high. ", GuessNumber(11, 10, 12));
	EXPECT_EQ("Well done, you guessed the number!\n", GuessNumber(11, 10, 11));
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}