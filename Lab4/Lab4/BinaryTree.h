#pragma once
#include <iostream>
class BinaryTree
{
	struct BinaryNode
	{
		BinaryNode(int value, BinaryNode* parent = nullptr, unsigned index = 0)
			:value(value),parent(parent),index(index)
		{
			children[1] = nullptr;
			children[0] = nullptr;
		}
		int value;
		unsigned index;
		BinaryNode* parent;
		BinaryNode* children[2];
	};
	BinaryNode* root = nullptr;
public:
	BinaryTree(int root_value)
	{
		root = new BinaryNode(root_value);
	}
	~BinaryTree()
	{
		BinaryNode* cur = root;
		while (true)
		{
			if (cur->children[0])
			{
				cur = cur->children[0];
			}
			else if(cur->children[1])
			{
				cur = cur->children[1];
			}
			else
			{
				if (cur->parent)
				{
					BinaryNode* par = cur->parent;
					cur->parent->children[cur->index] = nullptr;
					delete cur;
					cur = par;
				}
				else
					break;
			}

		}
		delete root;
	}
	void add(int value)
	{
		BinaryNode* compare_node = root;
		while (true)
		{
			int go_to = 1;
			if (compare_node->value > value)
				go_to = 0;
			if (compare_node->children[go_to])
			{
				compare_node = compare_node->children[go_to];
			}
			else
			{
				BinaryNode* new_node = new BinaryNode(value, compare_node, go_to);
				compare_node->children[go_to] = new_node;
				break;
			}
		}
	}
	void view()
	{
		view(root, 0);
	}
private:
	void view(BinaryNode* cur, unsigned tabs)
	{
		for (size_t i = 0; i < tabs; i++)
		{
			std::cout << "  ";
		}
		std::cout << cur->value << std::endl;
		for (auto child : cur->children)
		{
			if (child)
			{
				view(child, tabs + 1);
			}
			else
			{
				for (size_t i = 0; i < tabs + 1; i++)
				{
					std::cout << "  ";
				}
				std::cout << "-" << std::endl;
			}

		}
	}
};

