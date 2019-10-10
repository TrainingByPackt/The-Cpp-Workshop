//Chapter 6 : Exercise 48

#include "pch.h"
#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
struct numeric_item
{
	int value_;
	numeric_item* next_;
};

numeric_item* head = nullptr;

void add(int v, numeric_item** pp)
{
	numeric_item* newp = new numeric_item;
	newp->value_ = v;
	newp->next_ = *pp;
	*pp = newp;
}

numeric_item** find(int v, numeric_item** pp)
{
	while ((*pp) != nullptr && (*pp)->value_ != v)
	{
		pp = &((*pp)->next_);
	}
	return pp;
}

void print()
{
	for (numeric_item* p = head; p != nullptr; p = p->next_)
	{
		out << p->value_ << " ";
	}
	out << endl;
}
std::string TestCase() {
	for (int i = 1; i < 10; i = i + 2)
	{
		add(i, &head);
	}
	print();

	numeric_item** pp;
	pp = find(7, &head);
	add(8, pp);
	print();

	add(0, find(-1, &head));
	print();

	while (head != nullptr)
	{
		numeric_item* p = head;
		head = head->next_;
		out << "deleting " << p->value_ << endl;
		delete p;
	}

	return out.str();
}

TEST(Chapter6, Exercise48) {

	EXPECT_EQ("9 7 5 3 1 \n9 8 7 5 3 1 \n9 8 7 5 3 1 0 \ndeleting 9\ndeleting 8\ndeleting 7\ndeleting 5\ndeleting 3\ndeleting 1\ndeleting 0\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}