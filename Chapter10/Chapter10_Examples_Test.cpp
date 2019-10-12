//Chapter 10 : Example 1 

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;

class MyBaseClass
{
public:
	virtual void PrintMessage()
	{
		out << "Hello ";
	}
};

class MyDerivedClass : public MyBaseClass
{
public:
	void PrintMessage() override
	{
		out << "World!";
	}
};

std::string TestCase() {
	MyDerivedClass obj;
	obj.PrintMessage();

	return out.str();
}

TEST(Chapter10, Example1) {

	EXPECT_EQ("World!", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}


// Chapter 10 : Example 2

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;

class MyBaseClass
{
public:
	virtual void PrintMessage()
	{
		out << "Hello ";
	}
};

class MyDerivedClass : public MyBaseClass
{
public:
	void PrintMessage() override
	{
		MyBaseClass::PrintMessage();
		out << "World!";
	}
};

std::string TestCase() {
	MyDerivedClass obj;
	obj.PrintMessage();

	return out.str();
}

TEST(Chapter10, Example2) {

	EXPECT_EQ("Hello World!", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}


//Chapter 10 : Example 3

#include "pch.h"
#include <iostream>
#include <memory>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;

class MyClassA
{
public:
	virtual std::string GetString() = 0;
};

class MyClassB : public MyClassA
{
public:
	std::string GetString() override
	{
		return "Hello ";
	}
};

class MyClassC : public MyClassA
{
public:
	std::string GetString() override
	{
		return " world!";
	}
};

std::string TestCase() {
	MyClassA* myClass = new MyClassB();
	out << myClass->GetString();

	myClass = new MyClassC();
	out << myClass->GetString();

	return out.str();
}

TEST(Chapter10, Example3) {

	EXPECT_EQ("Hello  world!", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}