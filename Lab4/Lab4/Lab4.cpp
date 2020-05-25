#include <iostream>
#include <random>
#include <vector>
#include <Windows.h>
#include "Tree.h"
#include "BinaryTree.h"
using namespace std;
int user_input(string text = "")
{
	cout << text << endl << ">>";
	int InPut;
	cin >> InPut;
	return InPut;
}
BinaryTree* rand_binary_tree()
{
	BinaryTree* B = new BinaryTree(rand() % 15 + 1);
	for (int i = 0; i < 50 || rand() < RAND_MAX / 2; ++i)
		B->add(rand() % 20);
	return B;
}
void Interactive_Binary_Tree_mode()
{
	BinaryTree* B;
	switch (user_input("1 - to randomize tree, 2 - live empty .    0 - exit , -1 - go back "))
	{
	case 1:
		B = rand_binary_tree();
		break;
	case 2:
		B = new BinaryTree(user_input("Enter first element :"));
		break;
	case -1:
		return;
		break;
	default:
		exit(0);
	}
	B->view();
	delete B;
}
Tree* rand_regular_tree()
{
	Tree* tree = new Tree(rand() % 20);
	vector<int> address(0);
	while (rand() > RAND_MAX / 6)
	{
		if (rand() > RAND_MAX / 2)
		{
			tree->add_node(rand() % 20, address);
		}
		else
		{
			address.push_back(0);
			tree->add_node(rand() % 20, address);
		}

	}
	return tree;
}
int main();

void Interactive_Regular_Tree_mode()
{
	Tree* T;
	switch (user_input("1 - to randomize tree, 2 - live empty .    0 - exit , -1 - go back "))
	{
	case 1:
		T = rand_regular_tree();
		break;
	case 2:
		T = new Tree(user_input("Enter first element :"));
		break;
	case -1:
		return;
		break;
	default:
		exit(0);
	}
	while(1)
	switch (user_input("1 - view whole tree, 2 - interactive view with editing .  0 - exit, -1 - main menu"))
	{
	case 1:
		T->view();
		break;
	case 2:
		T->view_interactive();
		break;
	case -1:
		main();
		break;
	default :
		exit(0);
		break;
	}
}
void Interactive_mode()
{
	while(true)
	switch (user_input("Choose type of Tree:     1 - Regular, 2 - Binary. 0 - exit, 1 - go back."))
	{
	case 1:
		Interactive_Regular_Tree_mode();
		break;
	case 2:
		Interactive_Binary_Tree_mode();
		break;
	case 0:
		exit(0);
		break;
	case -1:
		return;
		break;
	}
}
void Demonstration_mode();

int main()
{

	while (true)
	switch (user_input("Choose mode:     1 - Interactive , 2 - Demonstration. 0 - exit"))
	{
	case 1:
		Interactive_mode();
		break;
	case 2:
		Demonstration_mode();
		break;
	case 0:
		return 0;
	}
}
void print_with_delay(string text, unsigned delay = 3500)
{
	Sleep(delay);
	cout << text <<endl;
}
void Demonstration_mode()
{
	system("cls");
	print_with_delay("Choose type of Tree:     1 - Regular, 2 - Binary. 0 - exit, 1 - go back.\n>> 1", 0);
	print_with_delay("1 - to randomize tree, 2 - live empty .    0 - exit , -1 - go back\n>> 1");
	print_with_delay("1 - view whole tree, 2 - interactive view with editing .  0 - exit, -1 - main menu\n>> 1");
	print_with_delay(">>1\n1\n> 0\n> 18\n > 4\n.11\n.1\n1 - view whole tree, 2 - interactive view with editing .  0 - exit, -1 - main menu\n >> 2");
	print_with_delay(""); 
	system("cls");
	print_with_delay("Path: {}\n-- > 1\n > 0\nType index of node to enter, -3 - to edit current branch. '-1' - to go back. '-2' - to exit\n >> 0",0);
	print_with_delay("");
	system("cls");
	print_with_delay("Path: {0}\n-- > 0\n > 18\nType index of node to enter, -3 - to edit current branch. '-1' - to go back. '-2' - to exit\n >> 0", 0);
	print_with_delay("");
	system("cls");
	print_with_delay("Path: {0, 0}\n-- > 18\n > 4\n.1\nType index of node to enter, -3 - to edit current branch. '-1' - to go back. '-2' - to exit\n >> -3", 0);
	print_with_delay("Type index of child to delete. '-3' - to add child. '-2' - to exit\n >> -3");
	print_with_delay("Enter the value\n>> 123");
	print_with_delay("Path: {0, 0}\n-- > 18\n > 4\n.1\n.123\nType index of node to enter, -3 - to edit current branch. '-1' - to go back. '-2' - to exit\n >> -3", 0);
	print_with_delay("Type index of child to delete. '-3' - to add child. '-2' - to exit\n>> 2");
	print_with_delay("Path: {0, 0}\n-- > 18\n > 4\n.1\nType index of node to enter, -3 - to edit current branch. '-1' - to go back. '-2' - to exit\n >> -2");
	print_with_delay("");
	system("cls");
	print_with_delay("1 - view whole tree, 2 - interactive view with editing .  0 - exit, -1 - main menu\n>> 1\n1\n > 0\n> 18\n > 4\n.11\n.1\n1 - view whole tree, 2 - interactive view with editing .  0 - exit, -1 - main menu\n>> 0", 0);
	Sleep(3000);
	system("cls");
}