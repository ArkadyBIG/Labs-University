#include <iostream>
#include <vector>
using namespace std;
class ExpressionTree
{
	class Node
	{
	public:
		~Node()
		{
			if (left)
				delete left;
			if (right)
				delete right;
		}
		double value;
		bool calculated = false;
		string expression;
		void calculate();
		Node(string expression, Node* parent = nullptr);
		void view(unsigned tabs = 0);
		Node* parent = nullptr;
		Node* left = nullptr;
		Node* right = nullptr;
	};
	Node* root = nullptr;
	string expression;
public:
	~ExpressionTree()
	{
		if (root)
			delete root;
	}
	ExpressionTree(string expression)
		:expression(expression)
	{
		root = new Node(expression);
		cout << root->expression;
	}
	void print()
	{
		root->view();
	}
	double answer();
	
};
