#include <string>
#include <math.h>
#include "ExpressionTree.h"
using namespace std;
const string UNARY_MINUS_CHARS = "*/-+";


string split_by_lovest_operand(string expression, string& to_left, string& to_right)
{
    while (expression[0] == '(' && expression.back() == ')')
    {
        expression.pop_back();
        expression.erase(expression.begin());
    }
    int in_bracets = 0;
    ///+ - 
    for (int i = expression.size() - 1; i >= 0; --i)
    {
        if (expression[i] == ')')
            in_bracets++;
        else if (expression[i] == '(')
            in_bracets--;
        if (!in_bracets && (expression[i] == '+' || (expression[i] == '-' && i)))
        {
            if (expression[i] == '-' && find(UNARY_MINUS_CHARS.begin(), UNARY_MINUS_CHARS.end(), expression[i - 1])
                != UNARY_MINUS_CHARS.end())
                continue;
            for (int j = 0; j < expression.size(); ++j)
            {
                if (j < i)
                    to_left += expression[j];
                else if (j > i)
                    to_right += expression[j];

            }
            string out;
            out += expression[i];
            return out;
        }
    }
    if (in_bracets)
        throw "Correct your bracets";
    ///* /
    for (int i = expression.size() - 1; i >= 0; --i)
    {
        if (expression[i] == ')')
            in_bracets++;
        else if (expression[i] == '(')
            in_bracets--;
        if (!in_bracets && (expression[i] == '*' || expression[i] == '/'))
        {
            for (int j = 0; j < expression.size(); ++j)
            {
                if (j < i)
                    to_left += expression[j];
                else if (j > i)
                    to_right += expression[j];

            }
            string out;
            out += expression[i];
            return out;
        }
    }
    if (in_bracets)
        throw "Correct your bracets";
    ///unary minus
    if (expression[0] == '-')
    {
        expression.erase(expression.begin());
        to_left = expression;
        to_right = "";
        return "-";
    }
    if (expression[0] == 'c' || expression[0] == 's')
    {
        string func = string(expression.begin(), expression.begin() + 3);
        expression.erase(expression.begin(), expression.begin() + 4);
        expression.pop_back();
        to_left = expression;
        to_right = "";
        return func;
    }
    to_left = "";
    to_right = "";
    return expression;

}

void ExpressionTree::Node::calculate()
{
    if (left || right)
    {
        if (expression == "+")
        {
            value = left->value + right->value;
        }
        else if (expression == "-")
        {
            if (right)
                value = left->value - right->value;
            else
                value = -left->value;
        }
        else if(expression == "*")
        {
            value = left->value * right->value;
        }
        else if(expression == "/")
        {
            value = left->value / right->value;
        }
        else if(expression == "sin")
        {
            value = sin(left->value);
        }
        else if (expression == "cos")
        {
            value = cos(left->value);
        }
    }
    else
    {
        value = stod(expression);
    }
    calculated = true;
}

ExpressionTree::Node::Node(string expression, Node* parent)
    :parent(parent), expression(expression)
{
    string to_left, to_right;
    this->expression = split_by_lovest_operand(expression, to_left, to_right);
    
    if (to_left != "")
    {
        this->left = new Node(to_left, this);
    }
    if (to_right != "")
    {
        this->right = new Node(to_right, this);
    }
}

void ExpressionTree::Node::view(unsigned tabs)
{
    for (size_t i = 0; i < tabs; i++)
    {
        cout << "    ";
    }
    cout << this->expression << endl;
    if (left)
        left->view(tabs + 1);
    if (right)
        right->view(tabs + 1);
}

double ExpressionTree::answer()
{
    Node* cur = root;
    while (true)
    {
        if (cur->left && !cur->left->calculated)
        {
            cur = cur->left;
            continue;
        }
        if (cur->right && !cur->right->calculated)
        {
            cur = cur->right;
            continue;
        }
        cur->calculate();
        if (cur == root)
            break;
        cur = cur->parent;
    }
    return root->value;
}
