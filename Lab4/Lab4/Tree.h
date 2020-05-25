#pragma once
#include <vector>
#include <iostream>

class Tree
{

protected:
	class Node
	{
	public:
		int value;
		Node(int value, Node* parent = nullptr, bool is_binary = false)
			:value(value), parent(parent)
		{
			if (parent)
				this->index = parent->children.size();
			else
				this->index = 0;
			if (is_binary)
				children = { nullptr, nullptr };
		}
		Node* get_child(int index)
		{
			return children[index];
		}
		Node* get_parent()
		{
			return parent;
		}
		std::vector<int> get_address()
		{
			std::vector<int> address(0);
			get_address(address);
			return address;
		}
		virtual bool has_child(unsigned index)
		{
			if (children.size() > index)
				return true;
			return false;
		}
		void add_child(int value)
		{
			Node* child = new Node(value, this);
			this->children.push_back(child);
		}
		void print_children(unsigned tabs = 0)//if tabs = 0 only family itself is printed
		{
			for (auto child : children)
			{
				std::string offset;
				if (!tabs)
					offset = "     ";
				else
					for (unsigned i = 0; i < tabs ; i++)
					{
						offset += "   ";
					}
				std::cout << offset;
				if (child->children.size() > 0)
					std::cout << '>';
				else
					std::cout << '.';
				std::cout << child->value << std::endl;
				if (tabs)
					child->print_children(tabs + 1);
			}
		}
		
		void remove_from_parent()
		{
			if(parent)
				parent->children.erase(parent->children.begin() + index);
			index = 0;
			parent = nullptr;
		}
	public:
		void get_address(std::vector<int>& address)
		{
			if (parent)
			{
				address.insert(address.begin(), index);
				parent->get_address(address);
			}
				
		}
		Node* parent = nullptr;
		unsigned index;
		std::vector<Node*> children;
		
	};
	
	Tree(Node* root)
		:root(root){}
public:
	Tree(int root_value)
	{
		root = new Node(root_value, nullptr);
	}
	~Tree()
	{
		Node* cur = root;
		while (true)
		{
			if (cur->children.size())
			{
				cur = cur->children.back();
				continue;
			}
			if (cur->parent)
			{
				Node* next = cur->parent;
				cur->remove_from_parent();
				delete cur;
				cur = next;
			}
			else
				break;
		}
		delete root;
	}
	Node* root = nullptr;
	void add_node(int value, std::vector<int> address)
	{
		if(get_node(address))
			get_node(address)->add_child(value);
	}
	Node* get_node(std::vector<int> address)
	{
		Node* target = root;
		for (auto i : address)
			if(target && target->has_child(i))
				target = target->get_child(i);
		return target;
	}
	void view()
	{
		std::cout << root->value << std::endl;
		root->print_children(1);
	}
	void view_interactive()
	{
		Node* current_node = root;
		system("cls");
		while (true)
		{
			std::vector<int> current_address = current_node->get_address();
			std::cout << "Path: {";
			for (unsigned i = 0; i < current_address.size();++i)
			{
				if(i)
					std::cout << ", ";
				std::cout << current_address[i];
			}
			std::cout << "}\n";
			std::cout << "--> " << current_node->value << std::endl;
			current_node->print_children();
			int user_input;
			std::cout << "Type index of node to enter, -3 - to edit current branch. '-1' - to go back. '-2' - to exit\n>>";
			std::cin >> user_input;
			
			switch (user_input)
			{
			case -1:
				system("cls");
				if(current_node->get_parent())
					current_node = current_node->get_parent();
				break;
			case -2:
				system("cls");
				return;
			case -3:
				std::cout << "Type index of child to delete. '-3' - to add child. '-2' - to exit\n>>";
				std::cin >> user_input;
				switch (user_input)
				{
				case -3:
					std::cout << "Enter the value\n>>";
					std::cin >> user_input;
					current_node->add_child(user_input);
					break;
				case -2:
					return;
				default:
					if (user_input >= 0)
					{
						if (current_node->has_child(user_input))
						{
							current_node->get_child(user_input)->remove_from_parent();
						}
						else
							std::cout << "Index is out of range.\n";
					}
					else
					{
						std::cout << "Index cant be less than ZERO.\n";
					}
				}
				break;
			default:
				system("cls");
				if (user_input >= 0)
				{
					if (current_node->has_child(user_input))
					{
						current_node = current_node->get_child(user_input);
					}
					else
						std::cout << "Index is out of range.\n";
				}
				else
				{
					std::cout << "Index cant be less than ZERO.\n";
				}
				break;
			}
		}
	}
	Tree remove_sub_tree(std::vector<int> address)
	{
		Node* node_to_remove = get_node(address);
		node_to_remove->remove_from_parent();
		Tree sub_tree(node_to_remove);
		return sub_tree;
	}


};

