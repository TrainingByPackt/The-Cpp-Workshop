//Chapter 7 : Exercise 50

#include "pch.h"
#include <iostream>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;

struct numeric_item
{
	int value_;
	numeric_item* next_;
};

class numeric_list
{
	numeric_item* head_;
public:
	numeric_list() : head_(nullptr) {}
	~numeric_list();
	void print();
	void add(int v);
	numeric_item* find(int v);
};
numeric_list::~numeric_list()
{
	while (head_ != nullptr)
	{
		numeric_item* p = head_;
		head_ = head_->next_;
		out << "deleting " << p->value_ << endl;
		delete p;
	}
}

void numeric_list::print()
{
	for (numeric_item* p = head_; p != nullptr; p = p->next_)
	{
		out << p->value_ << " ";
	}
	out << endl;
}

void numeric_list::add(int v)
{
	numeric_item* newp = new numeric_item;
	newp->value_ = v;
	newp->next_ = head_;
	head_ = newp;
}

numeric_item* numeric_list::find(int v)
{
	for (numeric_item* p = head_; p != nullptr; p = p->next_)
	{
		if (p->value_ == v)
			return p;
	}
	return nullptr;
}


std::string TestCase() {

	numeric_list l;
	for (int i = 1; i < 6; ++i)
	{
		l.add(i);
	}
	l.print();

	numeric_item* p = l.find(4);
	if (p != nullptr)
		out << "found numeric_item 4" << endl;

	return out.str();
}

TEST(Chapter7, Exercise50) {

	EXPECT_EQ("5 4 3 2 1 \nfound numeric_item 4\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}