//Chapter 10 : Activity 10

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
struct AnimalInfo
{
	std::string name = "";
	std::string origin = "";
	int lifeExpectancy = 0;
	float weight = 0;
};

void PrintAnimalInfo(AnimalInfo info)
{
	out << "Name: " << info.name << std::endl;
	out << "Origin: " << info.origin << std::endl;
	out << "Life Expectancy: " << info.lifeExpectancy << std::endl;
	out << "Weight: " << info.weight << std::endl;
}

class Animal
{
public:
	AnimalInfo GetAnimalInfo() const { return animalInfo; };

protected:
	AnimalInfo animalInfo;
};

class Lion final : public Animal
{
public:
	Lion()
	{
		animalInfo.name = "Lion";
		animalInfo.origin = "Africa";
		animalInfo.lifeExpectancy = 12;
		animalInfo.weight = 190;
	}
};

class Tiger final : public Animal
{
public:
	Tiger()
	{
		animalInfo.name = "Tiger";
		animalInfo.origin = "Africa";
		animalInfo.lifeExpectancy = 17;
		animalInfo.weight = 220;
	}
};

class Bear final : public Animal
{
public:
	Bear()
	{
		animalInfo.name = "Bear";
		animalInfo.origin = "Eurasia";
		animalInfo.lifeExpectancy = 22;
		animalInfo.weight = 270;
	}
};

std::string TestCase(int userChoice) {
	std::vector<Animal*> animals;
	animals.push_back(new Lion());
	animals.push_back(new Tiger());
	animals.push_back(new Bear());

	for (size_t i = 0; i < animals.size(); ++i)
	{
		out << i << ") " << animals[i]->GetAnimalInfo().name << std::endl;
	}

	// Sanity user input
	if (userChoice == -1)
	{
		out << "invalid userChoice \n";
		return out.str();

	}
	else if (userChoice < -1 || userChoice >((int)animals.size() - 1))
	{
		out << "\nInvalid Index. Please enter another.\n";
	}
	else
	{
		// Print animal info
		out << std::endl;
		PrintAnimalInfo(animals[userChoice]->GetAnimalInfo());
	}

	// Cleanup.
	for (size_t i = 0; i < animals.size(); ++i)
	{
		delete animals[i];
		animals[i] = nullptr;
	}
	animals.clear();

	return out.str();
}

TEST(Chapter10, Activity10) {

	EXPECT_EQ("0) Lion\n1) Tiger\n2) Bear\n\nName: Tiger\nOrigin: Africa\nLife Expectancy: 17\nWeight: 220\n", TestCase(1));
	EXPECT_EQ("0) Lion\n1) Tiger\n2) Bear\n\nName: Tiger\nOrigin: Africa\nLife Expectancy: 17\nWeight: 220\n0) Lion\n1) Tiger\n2) Bear\ninvalid userChoice \n", TestCase(-1));
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}