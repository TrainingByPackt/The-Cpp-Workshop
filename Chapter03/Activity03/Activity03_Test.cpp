//Chapter 3 : Activity 03


#include "pch.h"
#include <iostream>
#include "gtest/gtest.h"
using namespace std;
struct Person
{
	int age = 0;
	std::string name = "";
};

std::vector<Person> records;

void AddRecord(std::string newName, int newAge)
{
	Person newRecord;
	newRecord.name = newName;
	newRecord.age = newAge;

	records.push_back(newRecord);
};

Person FetchRecord(int userID)
{
	return records.at(userID);
};


std::string TestCase(std::string inputString, std::string name, std::string age) {

	std::ostringstream out;
	// Determine user selection.
	switch (std::stoi(inputString))
	{
	case 1:
	{
		AddRecord(name, std::stoi(age));
	}
	break;

	case 2:
	{
		int userID = 0;
		userID = std::stoi(name);

		Person person;
		try
		{
			person = FetchRecord(userID);
		}
		catch (const std::out_of_range & oor) {
			out << "\nError: Invalid UserID.\n\n";
			break;
		}

		out << "User Name: " << person.name << "\n";
		out << "User Age: " << person.age << "\n\n";
	}
	break;

	default:
		out << "\n\nError: Invalid option selection.\n\n";
		break;
	}
	return out.str();
}

TEST(Chapter3, Activity03) {

	EXPECT_EQ("", TestCase("1", "Mukesh", "28"));
	EXPECT_EQ("", TestCase("1", "Rakesh", "40"));
	EXPECT_EQ("", TestCase("1", "Prakash", "12"));
	EXPECT_EQ("User Name: Prakash\nUser Age: 12\n\n", TestCase("2", "2", ""));
	EXPECT_EQ("User Name: Mukesh\nUser Age: 28\n\n", TestCase("2", "0", ""));
	EXPECT_EQ("\n\nError: Invalid option selection.\n\n", TestCase("5", "Prakash", "12"));
	EXPECT_EQ("\nError: Invalid UserID.\n\n", TestCase("2", "10", ""));
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
