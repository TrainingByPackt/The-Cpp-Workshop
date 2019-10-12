//Chapter 12 : Exercise 78 

#include "pch.h"
#include <iostream>
#include <memory>
#include <typeinfo>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
class Person
{
public:

	Person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}

	string getName() const { return m_name; }
	int getAge() const { return m_age; }

private:

	string m_name;
	int m_age;
};
struct customComparator
{
	bool operator() (const Person& a, const Person& b) const
	{
		return (a.getAge() > b.getAge());
	}
};

std::string TestCase() {
	set<Person, customComparator> personSet;

	Person a("bob", 35);
	Person b("bob", 25);

	personSet.insert(a);
	personSet.insert(b);

	for (auto person : personSet)
	{
		out << person.getAge() << endl;
	}

	return out.str();
}

TEST(Chapter12, Exercise78) {

	EXPECT_EQ("35\n25\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}