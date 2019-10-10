//Chapter 6 : Activity 06

#include "pch.h"
#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

std::ostringstream out;
struct numeric_tree
{
	int value_;
	numeric_tree* left_;
	numeric_tree* right_;
};

numeric_tree* root = nullptr;

void add(int v, numeric_tree** pp)
{
	*pp = new numeric_tree;
	(*pp)->value_ = v;
	(*pp)->left_ = (*pp)->right_ = nullptr;
}

void delete_tree(numeric_tree* item)
{
	if (item == nullptr)
	{
		return;
	}
	else
	{
		delete_tree(item->left_);
		delete_tree(item->right_);
		out << "deleting " << item->value_ << endl;
		delete item;
	}
}

numeric_tree** find(int v, numeric_tree** pp)
{
	if (*pp == nullptr)
	{
		return pp;
	}
	else if (v < (*pp)->value_)
	{
		return find(v, &((*pp)->left_));
	}
	else
	{
		return find(v, &((*pp)->right_));
	}
}

void print(numeric_tree* item)
{
	if (item == nullptr)
	{
		return;
	}
	else
	{
		print(item->left_);
		out << item->value_ << " ";
		print(item->right_);
	}
}

std::string TestCase() {
	int insert_order[]{ 4, 2, 1, 3, 6, 5 };
	for (int i = 0; i < 6; ++i)
	{
		int v = insert_order[i];
		add(v, find(v, &root));
	}

	print(root);
	out << endl;

	delete_tree(root);

	return out.str();
}

TEST(Chapter6, Activity06) {

	EXPECT_EQ("1 2 3 4 5 6 \ndeleting 1\ndeleting 3\ndeleting 2\ndeleting 5\ndeleting 6\ndeleting 4\n", TestCase());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}